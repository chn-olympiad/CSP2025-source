#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n, q;
string s1[200001], s2[200001];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i];
    }
    for (int i = 1; i <= q; i++) {
        int cnt = 0;
        string t1, t2;
        cin >> t1 >> t2;
        int l = 0, r = t1.size() - 1;
        while (l < t1.size() && t1[l] == t2[l]) {
            l++;
        }
        while (r >= 0 && t1[r] == t2[r]) {
            r--;
        }
        //out << l << " " << r << endl;
        for (int i = 0; i < t1.size(); i++) {
            for (int j = i; j < t1.size(); j++) {
                if (i > l || j < r) {
                    continue;
                }
                //cout << l << " " << r << endl;
                for (int k = 1; k <= n; k++){
                    if (s1[k] == t1.substr(i, j - i + 1) && s2[k] == t2.substr(i, j - i + 1)) {
                        cnt++;
                        //cout << i << " " << j << " " << k << endl;
                    }
                    //cout << i << " " << j << " " << cnt << endl;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
