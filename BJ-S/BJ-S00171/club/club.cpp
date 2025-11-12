#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T,n,a[N][3],fl[N],ans,b[N];
vector <int> v[3];
void solve() {
    cin >> n; ans = 0;
    v[0].clear(); v[1].clear(); v[2].clear();
    for(int i = 1;i <= n;i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if(a[i][0] >= a[i][1]) {
            if(a[i][0] >= a[i][2]) fl[i] = 0;
            else fl[i] = 2;
        }
        else {
            if(a[i][1] >= a[i][2]) fl[i] = 1;
            else fl[i] = 2;
        }
        b[i] = 1e9; ans += a[i][fl[i]];
        for(int j = 0;j < 3;j++) {
            if(j == fl[i]) continue;
            b[i] = min(b[i],a[i][fl[i]] - a[i][j]);
        }
        v[fl[i]].push_back(b[i]);
    }
    for(int i = 0;i < 3;i++) {
        int siz = v[i].size();
        if(siz <= n / 2) continue;
        sort(v[i].begin(),v[i].end());
        for(int j = 0;j < siz - n / 2;j++) ans -= v[i][j];
    }
    cout << ans << "\n";
    return ;
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}