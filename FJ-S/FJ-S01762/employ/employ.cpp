#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define il inline
#define ll long long
#define pb push_back
const int N = 505, mod = 998244353;
int n, m, ans, a[N], c[N], sc[N], A[N][N], C[N][N], f[N][N][N]; string s;
il int ad(int x, int y) {return (x + y >= mod ? x + y - mod : x + y);}
il void add(int &x, int y) {if ((x += y) >= mod) x -= mod;}
il int ml(int x, int y) {return 1ll * x * y % mod;}
il void mul(int x, int y) {x = 1ll * x * y % mod;}
int main()
{
    FILE("employ");
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < N; i++)
    {
        A[i][0] = C[i][0] = 1;
        for (int j = 1; j <= i; j++) A[i][j] = ml(A[i][j-1], i - j + 1), C[i][j] = ad(C[i-1][j-1], C[i-1][j]);
    }
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) cin >> a[i], c[a[i]]++;
    sc[0] = c[0]; for (int i = 1; i <= n; i++) sc[i] = sc[i-1] + c[i];
    f[0][0][0] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j <= i; j++) for (int k = 0; k <= n - sc[j]; k++)
    {
        if (!f[i][j][k]) continue;
        int x = sc[j] - (i - k), y = n - sc[j] - k;
        if (x) for (int o = 0; o <= k; o++) add(f[i+1][j+1][k-o], ml(f[i][j][k], ml(x, ml(C[k][o], A[c[j+1]][o])))); 
        if (y)
        {
            if (s[i] == '1') add(f[i+1][j][k+1], f[i][j][k]);
            else for (int o = 0; o <= k + 1; o++) add(f[i+1][j+1][k+1-o], ml(f[i][j][k], ml(C[k+1][o], A[c[j+1]][o]))); 
        }
    }
    for (int j = 0; j <= n - m; j++) add(ans, ml(f[n][j][n-sc[j]], A[n-sc[j]][n-sc[j]]));
    cout << ans << "\n";
    return 0;
}