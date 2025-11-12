#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string a[N], b[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    while(q--){
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int fi = t1.find(a[i]);
            if(fi >= 0 && fi <= t1.size()){
                string t3 = t1;
                t3.replace(fi, a[i].size(), b[i], 0, b[i].size());
                if(t3 == t2){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}