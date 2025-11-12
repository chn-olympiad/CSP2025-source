#include <fstream>
#include <string>

using namespace std;

ifstream cin("replace.in");
ofstream cout("replace.out");

const int N = 2e5+5;

string s1[N], s2[N];

int main() {
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++) {
        cin >> s1[i] >> s2[i];
    }
    for(int i=0; i<q; i++) {
        string t1, t2;
        cin >> t1 >> t2;
        int ps = 2e9, pe;
        for(int  i=0; i<t1.size(); i++) {
            if(t1[i] != t2[i]) {
                ps = min(ps, i);
                pe = i;
            }
        }
        int s = 0;
        for(int i=0; i<n; i++) {
            if(s1[i].size() < pe-ps+1) {
                continue;
            }
            int c = max(0, pe - ((int)s1[i].size()-1));
            while(true) {
                c = t1.find(s1[i], c);
                if(c > pe) {
                    break;
                }
                if(c == t1.npos) {
                    break;
                }
                if(
                   c <= ps && pe <= c+s1[i].size()-1 &&
                   t2.substr(c, s1[i].size()) == s2[i]
                   ) {
                    s++;
                }
                c++;
            }
        }
        cout << s << endl;
    }
    return 0;
}

