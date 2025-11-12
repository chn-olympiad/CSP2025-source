#include "fstream"
#include "vector"

using namespace std;


int main() {
    ifstream inf("xor.in");
    ofstream outf("xor.ans");
    bool spe_A = true, spe_B = true;
    int n, k;
    inf >> n >> k;
    if (k != 0) {
        spe_A = false;
        if (k != 1) {
            spe_B = false;
        }
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        inf >> a.at(i);
        if (a.at(i) != 1) {
            spe_A = false;
            if (a.at(i) != 0) {
                spe_B = false;
            }
        }
    }
    if (spe_A) {
        outf << n / 2;
    }
    else if (spe_B) {
        if (k == 0) {
            int i = 0, r = 0;
            while (i < n) {
                if (a.at(i) == 0) {
                    r++;
                    i++;
                }
                else if (i + 1 < n && a.at(i + 1) == 1){
                    r++;
                    i += 2;
                }
                else {
                    i++;
                }
            }
            outf << r;
        }
        else if (k == 1) {
            int i = 0, r = 0;
            while (i < n) {
                if (a.at(i) == 1) {
                    r++;
                    i++;
                }
                else {
                    i++;
                }
            }
            outf << r;
        }
    }
    else {
        outf << 0;
    }
}
