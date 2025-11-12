#include <bits/stdc++.h>
using namespace std;
#define int long long
#define reint register int
#define ii inline
#define reitn reint
#define itn int
#define pii pair<int, int>
int T;
int n;
int a[100005], b[100005], c[100005];
vector<int> ji[3];
vector<int> x[3];
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >>T;
    while(T--) {
        ji[0].clear();
        ji[1].clear();
        ji[2].clear();
        x[0].clear();
        x[1].clear();
        x[2].clear();
        cin >> n;
        for(reint i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        itn ans = 0;
        for(reint i = 1; i <= n; i++) {
            if(a[i] >= b[i] && a[i] >= c[i]) {
                ans += a[i];
                ji[0].push_back(i);
                x[0].push_back(max(b[i], c[i]) - a[i]);
            }else if(b[i] >= a[i] && b[i] >= c[i]) {
                ans += b[i];
                ji[1].push_back(i);
                x[1].push_back(max(a[i], c[i]) - b[i]);
            }else if(c[i] >= a[i] && c[i] >= b[i]) {
                ans += c[i];
                ji[2].push_back(i);
                x[2].push_back(max(a[i], b[i]) - c[i]);
            }
        }
        if(ji[0].size() <= n / 2 && ji[1].size() <= n / 2 && ji[2].size() <= n / 2) {
            cout << ans <<"\n";
        }else {
            if(ji[0].size() > n / 2) {
                sort(x[0].begin(), x[0].end(), greater<int>());
                for(reint i = 0; i < ji[0].size(); i++){
     //               cout << x[0][i] << " ";
                }
                for(reint i = 0; i < (ji[0].size() - n / 2); i++) {
                    ans = ans + x[0][i];
                }
            }else if(ji[1].size() > n / 2) {
                sort(x[1].begin(), x[1].end(), greater<int>());
                for(reint i = 0; i < (ji[1].size() - n / 2); i++) {
                    ans = ans + x[1][i];
                }
            }else {
                sort(x[2].begin(), x[2].end(), greater<int>());
                for(reint i = 0; i < (ji[2].size() - n / 2); i++) {
                    ans = ans + x[2][i];
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
