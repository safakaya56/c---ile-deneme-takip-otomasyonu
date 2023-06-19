#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void kayitEkleme() {
    string ad, soyad, sifre,konu,satir,calismaKontrol;
    int numara, deneme, matnet, fennet, trnet, sosnet;

    bool bulundu = false;

    ifstream ogretmen("ogretmen.txt", ios::in);

    if (ogretmen.is_open()) {
        string ogretmenSoyad, ogretmenSifre;

        cout << "->Kayit ekleme yalnizca ogretmenler icindir. Lutfen soyad ve size ait ozel sifrenizi girin.<-" << endl;
        cout<<endl;
		cout << "Soyadinizi girin: ";
        getline(cin >> ws, soyad);
        cout << "Sifrenizi girin: ";
        getline(cin >> ws, sifre);
        cout<<endl;
        while (getline(ogretmen, satir)) {
            istringstream ss(satir);
            ss >> ogretmenSoyad >> ogretmenSifre;

            if (ogretmenSoyad == soyad && ogretmenSifre == sifre) {
                
				bulundu = true;
				cout<<endl;
				cout<<"->Erisim saglandi.Kayit ekleyebilirsiniz.<-\n"<<endl;

                ofstream dosya("kayit.txt", ios::app);

                if (dosya.is_open()) {
                    cout << "Ad: ";
                    getline(cin >> ws, ad);

                    cout << "Soyad: ";
                    getline(cin >> ws, soyad);

                    cout << "Okul Numarasi: ";
                    cin >> numara;

                    cout << "Deneme Numarasi: ";
                    cin >> deneme;

                    cout << "Matematik Neti: ";
                    cin >> matnet;

                    cout << "Fen Neti: ";
                    cin >> fennet;

                    cout << "Turkce Neti: ";
                    cin >> trnet;

                    cout << "Sosyal Neti: ";
                    cin >> sosnet;
                    
                    cout << "Calismasi Gereken Konular: ";
                    getline(cin >> ws, konu);
                    
                    cout << "Calismasi gereken konu calisildi mi?(ilk deneme icin 'ilk deneme' diger denemeler icin 'EVET' veya 'HAYIR' yaziniz) : ";
                    getline(cin >> ws, calismaKontrol);
                    

                    dosya << ad << "#" << soyad << "#" << numara << "#" << deneme
                          << "#" << matnet << "#" << fennet << "#" << trnet << "#"
                          << sosnet << "#" << konu << "#" << calismaKontrol << "#" << endl;
                    
                    cout<<endl;
                    cout << "->Kayit Basariyla Eklendi<-" << endl;
                }
                break;
            }
        }

        ogretmen.close();

        if (!bulundu) {
            cout << "->Erisim saglayamadiniz,lutfen bilgilerinizi kontrol edin!<-" << endl;
        }
    } 
	else {
        cout << "->Dosya acilamadi<-" << endl;
    }
}


void kayitArama() {
    string satir, sutun, ad, soyad, numara;
    vector<string> ogrBilgi;
    cout<<endl;
    cout << "->Lutfen aramak istediginiz ogrenci ad soyad ve numarasini girin<-"<<endl;;
    cout<<endl;
    cout << "Ad: ";
    getline(cin >> ws, ad);

    cout << "Soyad: ";
    getline(cin >> ws, soyad);

    cout << "Okul Numarasi: ";
    getline(cin >> ws, numara);

    ifstream dosya("kayit.txt", ios::in);
    
    if (dosya.is_open()) {
        bool bulundu = false;
        while (getline(dosya, satir)) {
            istringstream ss(satir);
            while (getline(ss, sutun, '#')) {
                ogrBilgi.push_back(sutun);
            }
            if (ogrBilgi[0] == ad && ogrBilgi[1] == soyad && ogrBilgi[2] == numara) {
                bulundu = true;
                
                cout<<"-------------"<<endl;
                cout<<"Kayit bulundu"<<endl;
                cout<<"-------------"<<endl;
                cout << "Ad: " << ogrBilgi[0] << endl;
                cout << "Soyad: " << ogrBilgi[1] << endl;
                cout << "Okul Numarasi: " << ogrBilgi[2] << endl;
                cout << "Deneme Numarasi: " << ogrBilgi[3] << endl;
                cout << "Matematik Neti: " << ogrBilgi[4] << endl;
                cout << "Fen Neti: " << ogrBilgi[5] << endl;
                cout << "Turkce Neti: " << ogrBilgi[6] << endl;
                cout << "Sosyal Neti: " << ogrBilgi[7] << endl;
                cout << "Calismasi Gereken Konular: " << ogrBilgi[8] << endl;
                cout << "Calismasi Gereken Konular Calisildi mi?: " << ogrBilgi[9] << endl;
            }
            ogrBilgi.clear();
        }
        if (!bulundu) {
            cout << "->Aradiginiz ogrenci kayitlarda bulunamadi<-" << endl;
        }
    }
	    else {
        cout << "->Dosya acilamadi<-" << endl;
    }
    
    dosya.close();
}

void ogretmenKayit(){
	
	string ogretmenSoyad,ogretmenSifre;
	cout <<"->Kayit ekleme yapabilmek icin soyad ve olusturacaginiz sifre ile yeni bir ogretmen kaydi olusturunuz.<-"<<endl;
	cout<<endl;
	ofstream ogretmen("ogretmen.txt",ios::app);
	
	if (ogretmen.is_open()){
		
		cout << "Soyadinizi girin: ";
		getline(cin>>ws,ogretmenSoyad);
		cout << "Sifrenizi girin: ";
		getline(cin>>ws,ogretmenSifre);
		
		ogretmen<<" "<<ogretmenSoyad<<" "<<ogretmenSifre<<" "<<endl;
		cout<<endl;
		cout <<"->Kaydiniz basari ile eklendi<-"<<endl;
		
	}
	else{
		cout <<"->Dosya acilamadi<-"<<endl;
	}
	
	ogretmen.close();
	}

int main() {
    int secim = 0;
    
	cout<<string(28,'-')<<endl;
	cout<<"OGRENCI DENEME TAKIP SISTEMI"<<endl;
    cout<<string(28,'-')<<endl;
   
    while (secim != 4) {  
        cout << "1. OGRENCI KAYIT EKLEME" << endl;
        cout << "2. OGRENCI KAYIT ARAMA" << endl;
        cout << "3. OGRETMEN KAYIT EKLEME"<<endl;
	    cout << "4. CIKIS YAP"<<endl;
	    cout <<endl;
        cout << "Seciminiz: ";
        cin >> secim;
        cout<<endl;
        switch (secim) {
            case 1:
                kayitEkleme();
                break;
            case 2:
                kayitArama();
                break;
            case 3:
                ogretmenKayit();
              break;
            case 4:
            	cout <<"->Program sonlandirildi<-" <<endl;
			default:
            cout << "->Gecersiz islem yaptiniz.Lutfen menuler arasinda secim yapiniz.<- " << endl;
            break;
        }
    cout<<endl;
	}
    return 0;
}

