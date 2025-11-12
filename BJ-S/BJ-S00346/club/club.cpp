#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[5][100005];
vector<int> v[5];
int f(int x){
    if (a[1][x] >= a[2][x] && a[2][x] >= a[3][x]) return a[1][x] - a[2][x];
    if (a[1][x] >= a[3][x] && a[3][x] >= a[2][x]) return a[1][x] - a[3][x];
    if (a[2][x] >= a[1][x] && a[1][x] >= a[3][x]) return a[2][x] - a[1][x];
    if (a[2][x] >= a[3][x] && a[3][x] >= a[1][x]) return a[2][x] - a[3][x];
    if (a[3][x] >= a[1][x] && a[1][x] >= a[2][x]) return a[3][x] - a[1][x];
    if (a[3][x] >= a[2][x] && a[2][x] >= a[1][x]) return a[3][x] - a[2][x];
}
bool cmp(int x,int y){
    return f(x) < f(y);
}
void solve(){
    v[1].clear();
    v[2].clear();
    v[3].clear();
    int ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[1][i] >> a[2][i] >> a[3][i];
        if (a[1][i] >= a[2][i] && a[1][i] >= a[3][i]) v[1].push_back(i),ans += a[1][i];
        else if (a[2][i] >= a[1][i] && a[2][i] >= a[3][i]) v[2].push_back(i),ans += a[2][i];
        else v[3].push_back(i),ans += a[3][i];
    }
    int tmp = -1;
    if (v[1].size() > n / 2) tmp = 1;
    if (v[2].size() > n / 2) tmp = 2;
    if (v[3].size() > n / 2) tmp = 3;
    if (tmp == -1){
        cout << ans << "\n";
        return;
    }
    sort(v[tmp].begin(),v[tmp].end(),cmp);
    for (int i = 0;i < v[tmp].size() - n / 2;i++) ans -= f(v[tmp][i]);
    cout << ans << "\n";
}
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while (T--) solve();
    return 0;
}