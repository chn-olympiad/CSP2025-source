#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;
const int m = 998244353;
int n, lg, a[5050];
int c[5050][5050];
bool f = 0;

int dfs(int u,int ma){
    long long ans = 0;
    //cout << a[u] << ' ';
    for(int v = u + 1; v < n; ++v){
        lg += a[u];
        ans += dfs(v, max(ma, a[v]));
        ans %= m;
        lg -= a[u];
    }
    //if(lg + a[u] > 2 * ma) cout << 'x' << a[u] << ' ';
    return ans + (long long)(lg + a[u] > 2 * ma);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if( a[i] > 1) f = 1;
    }
    int cnt = 0;
    if(f){
        stable_sort(a, a + n - 1);
        for(int i = 0; i < n; ++i){
            cnt += dfs(i, a[i]);
            cnt %= m;
        }
    }else {
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % m;
        for(int i = 1; i <= n; ++i){
            cnt += c[n][i];
            cnt %= m;
        }
    }
    cout << cnt << '\n';
    return 0;
}
