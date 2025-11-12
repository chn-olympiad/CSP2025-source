#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string a[200005],b[200005];
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i++) cin >> a[i] >> b[i];
    while (q--){
        string A,B;
        cin >> A >> B;
        int ans = 0;
        for (int i = 1;i <= n;i++) for (int j = 0;j < (int)A.size() - (int)a[i].size() + 1;j++) if (A.substr(j,a[i].size()) == a[i]){
            string tmp = A;
            for (int k = j;k < j + a[i].size();k++) tmp[k] = b[i][k - j];
            if (tmp == B){
                ans++;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}