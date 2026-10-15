#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class Prajitura {
public:
    char* denumire;
    float pret;
    int cantitate;
    bool dePost;
    int nrIngrediente;
    string* ingrediente;

    Prajitura() {
        this->denumire = new char[strlen("Tiramisu") + 1];
        strcpy(denumire, "Tiramisu");
        this->pret = 15;
        this->cantitate = 350;
        this->dePost = true;
        this->nrIngrediente = 3;
        this->ingrediente = new string[this->nrIngrediente];
        this->ingrediente[0] = "piscoturi";
        this->ingrediente[1] = "vanilie";
        this->ingrediente[2] = "cafea";
    }

    Prajitura(const char* denumire, float pret) {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy(this->denumire, denumire);
        this->pret = 15;
        this->cantitate = 350;
        this->dePost = true;
        this->nrIngrediente = 3;
        this->ingrediente = new string[this->nrIngrediente];
        this->ingrediente[0] = "piscoturi";
        this->ingrediente[1] = "vanilie";
        this->ingrediente[2] = "cafea";
    }

    void afisare() { //numim doar afisare deoarece este in interiorul clasei
        cout << "Denumire:" << this->denumire << endl;
        cout << "Pret:" << this->pret << endl;
        cout << "Cantitate:" << this->cantitate << endl;
        cout << "dePost:" << (this->dePost ? "DA" : "NU") << endl;
        cout << "nrIngrediente:" << this->nrIngrediente << endl;
        cout << "Ingredientele sunt: ";
        for (int i = 0; i < this->nrIngrediente; i++) {
            cout << this->ingrediente[i] << ", ";
        }
        cout << endl;
    }

    float costMediuGram() {
        if (cantitate == 0) {
            return 0;
        }
        else
            return this->pret / this->cantitate;
    }

    void modificaDenumire(const char* denumire) {
        delete this->denumire;
        this->denumire = new char[strlen(denumire) + 1];
        strcpy(this->denumire, denumire);
    }

    
};
float calculeazaCantitateaTotala(Prajitura* prajituri, int nr_prajituri) {
        float greutate = 0;
        for (int p = 0; p < nr_prajituri; p++)
            greutate += prajituri[p].cantitate;
        return greutate;
    }

int main() {
    Prajitura p2("Amandina", 40);
    p2.afisare();
    Prajitura p;
    p.afisare();
    cout << p.costMediuGram() << endl;
    Prajitura* prajituri;
    prajituri = new Prajitura[3];
    prajituri[2].afisare();
    prajituri[1].pret = 50;
    prajituri[2].cantitate = 70;

    prajituri[0].modificaDenumire("tort");
    prajituri[1].modificaDenumire("ecler");
    for (int i = 0; i < 3; i++)
    {    
        cout << prajituri[i].denumire << " " << prajituri[i].costMediuGram() << endl;
    }
        float greutate_totala = calculeazaCantitateaTotala(prajituri, 3);
        cout << "total: " << greutate_totala << endl;
    
    return 0;

}