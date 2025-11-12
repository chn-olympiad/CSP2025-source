#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using ll = long long;
ll n, w[N][5], a[N][5], k, ans, t, e, f;
vector <ll> v;

struct node{
    ll e, f, g;
}b[N];

void dfs(ll x, ll e, ll f, ll g, ll sum){
    if(e > (n + 1) / 2 || f > (n + 1) / 2  || g > (n + 1) / 2){
        return;
    }
    if(x == n + 1){
        ans = max(ans, sum);
        return;
    }
    dfs(x + 1, e + 1, f, g, sum + a[x][1]);
    dfs(x + 1, e, f + 1, g, sum + a[x][2]);
    dfs(x + 1, e, f, g + 1, sum + a[x][3]);
}

int cmp(const node &a, const node &b){
    return a.e > b.e;
}

int gz(const node &a, const node &b){
    return a.f - a.e > b.f - b.e;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        e = 0, f = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 3; j++){
                cin >> a[i][j];
            }
            if(a[i][2] != 0 || a[i][3] != 0){
                e = 1;
            }
            if(a[i][3] != 0){
                f = 1;
            }
        }
        if(n <= 1){
            dfs(1, 0, 0, 0, 0);
            cout << ans << '\n';
            ans = 0;
        }else if(e == 0){
            for(int i = 1; i <= n; i++){
                b[i].e = a[i][1];
                b[i].f = a[i][2];
                b[i].g = a[i][3];
            }
            sort(b + 1, b + n + 1, cmp);
            for(int i = 1; i <= n / 2; i++){
                ans += b[i].e;
            }
            cout << ans << '\n';
            ans = 0;
        }else if(f == 0){
            for(int i = 1; i <= n; i++){
                b[i].e = a[i][1];
                b[i].f = a[i][2];
                b[i].g = a[i][3];
                ans += a[i][1];
            }
            sort(b + 1, b + n + 1, gz);
            for(int i = 1; i <= n / 2; i++){
                ans += b[i].f - b[i].e;
            }
            cout << ans << '\n';
            ans = 0;
        }
    }
    return 0;
}
