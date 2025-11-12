#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<string, string> mp;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    for (int i = 1; i <= q; i++){
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()){
            cout << 0 << "\n";
            continue;
        }
        int cnt = 0;
        int l = 0, r = t1.length();
        for (int l = 0; l < t1.length(); l++){
            for (int len = 0; len <= t1.length()-l; len++){
                string y = t1.substr(l, len);
                if (mp[y] != ""){
                    string x = t1.substr(0, l), z = t1.substr(l+len, t1.length()-l-len);
                    string nt1 = x+mp[y]+z;
                    cout << x << " " << z << " " << nt1 << "\n";
                    if (nt1.compare(t2) == 0) cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
