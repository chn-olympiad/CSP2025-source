#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5005, mod = 998244353;
bool st;
int n, l[maxn], ans, f[maxn][maxn], sum[maxn][maxn];
bool ed;

void Add(int &x, int y){ ((x += y) >= mod) && (x -= mod); }

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> l[i];
    sort(l + 1, l + n + 1);
    f[0][0] = 1, sum[0][0] = 1;
    int lim = l[n] + 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= lim; j++){
            f[i][j] = f[i - 1][j];
        }
        for(int j = lim; j >= 0; j--){
            int k = min(lim, j + l[i]);
            Add(f[i][k], f[i - 1][j]);
        }
        for(int j = lim; j >= 0; j--){
            Add(sum[i][j], f[i][j]);
            Add(sum[i][j], sum[i][j + 1]);
        }
    }
    for(int i = n; i >= 3; i--){
        Add(ans, sum[i - 1][l[i] + 1]);
    }
    cout << ans;
    return 0;
}