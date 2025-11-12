#include "fstream"
#include "cstring"

using namespace std;

int main() {
    ifstream inf("number.in");
    ofstream outf("number.ans");
    string s;
    inf >> s;
    int a['9' + 1] = {0};
    for (int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            a[s[i]]++;
        }
    }
    for (char i = '9'; i >= '0'; i--) {
        while(a[i] > 0) {
            outf << i;
            a[i]--;
        }
    }
    return 0;
}
