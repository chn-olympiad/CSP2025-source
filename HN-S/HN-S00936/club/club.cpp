#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int t, n, a[N][4], id1[N], id2[N], b[N], d[N], p[5];

bool cmp(const int &ad, const int &bd){
    return a[ad][id1[ad]] - a[ad][id2[ad]] < a[bd][id1[bd]] - a[bd][id2[bd]];
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        id1[i] = id2[i] = 0;
        for(int j = 1; j <= 3; j++){
            if(a[i][j] >= a[i][id1[i]]) id2[i] = id1[i], id1[i] = j;
            else if(a[i][j] > a[i][id2[i]]) id2[i] = j;
        }
    }
    for(int i = 1; i <= n; i++) d[i] = i;
    sort(d + 1, d + n + 1, cmp);
    p[1] = p[2] = p[3] = 0;
    for(int i = 1; i <= n; i++) p[id1[i]]++;
    ll ans = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(p[id1[d[i]]] - cnt > n / 2) ans += a[d[i]][id2[d[i]]], cnt++;
        else ans += a[d[i]][id1[d[i]]];
    }
    cout << ans << '\n';
    return ;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) solve();
    return 0;
}
