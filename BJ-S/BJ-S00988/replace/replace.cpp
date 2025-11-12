#include <bits/stdc++.h>
using namespace std;
int n, q, resn[5000005];
string x, y, yh, z, s1[200005], s2[200005], t1[200005], t2[200005], res[5000005];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1;i <= q;i++)
        for (int j = 1;j <= n;j++){
            cin >> s1[j] >> s2[j];
        }
        for (int j = 1;j <= q;j++){
            cin >> t1[j] >> t2[j];
        }
        int ans = 0;
        for (int j = 1;j <= n;j++){
            resn[j] = 1e9;
            for (int k = j;k <= n;k++){
                res[j] += t1[k];
                resn[j] = min(resn[j], k);
            }
        }
        for (int j = 1;j <= n;j++){
            y = res[j];
            if (y == s1[j]){
                yh = s2[j];
                x = "", z="";
                for (int k = 1;k <= resn[j];k++){
                    x += t1[k];
                }
                for (int k = resn[j];k <= n;k++){
                    z += t1[k];
                }
                if ((x+yh+z) == t2[j]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}