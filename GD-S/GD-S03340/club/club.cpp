#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = (a) ; i <= (b) ; i++)
// #define DEBUG 
const int N = 400000 + 10;
int a[N][4];
void read(int &x){
    x = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        f = (ch == '-' ? -1 : 1), ch = getchar();
    while(ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x *= f;
}
int n;
void solve(){
    read(n);
    int ans = 0;
    vector<int> vec[4];
    rep(i, 1, n){
        read(a[i][1]);
        read(a[i][2]);
        read(a[i][3]);
        int mx = max({a[i][1], a[i][2], a[i][3]});
        ans += mx;
        if(mx == a[i][1])
            vec[1].emplace_back(a[i][1] - max(a[i][2], a[i][3]));
        else if(mx == a[i][2])
            vec[2].emplace_back(a[i][2] - max(a[i][1], a[i][3]));
        else 
            vec[3].emplace_back(a[i][3] - max(a[i][1], a[i][2]));
    }
    rep(i, 1, 3){
        if(vec[i].size() > n / 2){
            sort(vec[i].begin(), vec[i].end());
            for(int j = 0 ; j < (vec[i].size() - n / 2) ; j++)
                ans -= vec[i][j];
        }
    }
    printf("%lld\n", ans);
}
signed main(){
    #ifndef DEBUG
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    #endif
    int t;
    read(t);
    while(t--)
        solve();
    return 0;
}