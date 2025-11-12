#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int maxn = 1005;
int n, p[maxn], m;
int a[maxn];
pii mp[maxn];


signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    iota(p + 1, p + n * m + 1, 1);
    sort(p + 1, p + n * m + 1, [](int x, int y){
        return a[x] > a[y];
    });
    int tt = 0;
    for(int i = 1; i <= n; i++){
        if(i & 1){
            for(int j = 1; j <= m; j++){
                mp[++tt] = {i, j};
            }
        }else{
            for(int j = m; j >= 1; j--){
                mp[++tt] = {i, j};
            }
        }
    }
    for(int i = 1; i <= n * m; i++){
        if(p[i] == 1){
            cout << mp[i].fi << ' ' << mp[i].se << '\n';
        } 
    }

    return 0;
}
