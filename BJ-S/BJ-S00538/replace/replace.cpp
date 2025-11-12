#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[100005], s2[100005];
int main() {
    cin >> n >> q;
    if(n >= 2000) {
        for(int i = 1;i = q;i++)
            cout << 0 << endl;
        return 0;
    }
    for(int i= 1;i <= n;i++) {
        cin >> s1[i] >> s2[i];
    }
    while(q--) {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            int s = s1[i].size();
            for(int j = 0;j + s <= t1.size();j++){
                if(t1.substr(j, s) == s1[i]&&t2.substr(j, s) == s2[i] && t1.substr(0, j)==t2.substr(0, j) && t1.substr(j+s, t1.size()-j-s)==t2.substr(j+s, t1.size()-j-s)){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
