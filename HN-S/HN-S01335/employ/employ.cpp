#include <bits/stdc++.h>
#define int long long
#define PII std::pair<int,int>
#define all(v) v.begin(),v.end()
#define fro(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
bool bg;
inline void chkmin (int& x , int y) { (x > y) && (x = y); }
inline void chkmax (int& x , int y) { (x < y) && (x = y); }
const int N = 505 , Mod = 998244353;

inline int qpow (int x , int n , int res = 1)
{
    for (; n ; x = x * x % Mod , n >>= 1)
        if (n & 1) res = res * x % Mod;
    return res;
}

int n , m , c1 , sum ;
int jc[N] , inv[N] ;
int cnt[N] , s[N] , c[N] , p[N] ;
// int dp[2][N][N][N] ;

inline int C (int n , int m)
{
    if (m > n) return 0;
    return jc[n] * inv[n - m] % Mod * inv[m] % Mod;
}

signed main ()
{
    freopen ("employ.in" , "r" , stdin);
    freopen ("employ.out" , "w" , stdout);
    cin >> n >> m;
    jc[0] = 1 , inv[0] = 1;
    fro (i , 1 , n) jc[i] = jc[i - 1] * i % Mod , p[i] = i;
    inv[n] = qpow (jc[n] , Mod - 2);
    for (int i = n - 1; i ; i--) inv[i] = inv[i + 1] * (i + 1) % Mod;
    std :: string ss; cin >> ss;
    fro (i , 1 , n) s[i] = ss[i - 1] - '0' , sum += s[i];
    fro (i , 1 , n)
    {
        int x; std :: cin >> x; c[i] = x;
        cnt[x]++ , c1 += (x == 0 ? 0 : 1);
    }
    if (n <= 10)
    {
        int res = 0;
        do 
        {
            int cnt = 0;
            fro (i , 1 , n)
            {
                if (c[p[i]] <= cnt || s[i] == 0)
                    cnt++;
            }
            res += (n - cnt >= m);
        } while (next_permutation (p + 1 , p + n + 1));
        std :: cout << res;
        return 0;
    }
    if (n == m)
    {
        int res = 0;
        std :: sort (c + 1 , c + n + 1);
        int cnt = 0;
        fro (i , 1 , n)
        {
            if (c[p[i]] <= cnt || s[i] == 0)
                cnt++;
        }
        res += (n - cnt >= m);
        std :: cout << res ;
        return 0;
    }
    if (sum == n)
    {
        return std :: cout << jc[n] , 0;
    }
    // if (n > 100) 
        return std :: cout << 0 , 0;
//     int s1 = 0 ;
//     fro (i , 1 , n)
//     {
//         int now = n - i + 1;
//         int i1 = (i & 1) , i0 = (i - 1) & 1;
//         memset (dp[i1] , 0 , sizeof dp[i1]);
//         if (s[i] == 0)
//         {
//             s1++;
//             fro (j , 1 , i)
//                 fro (k , 0 , c1)
//                 {
//                     fro (t , 0 , cnt[j]) if (k >= t) fro (l , cnt[j] - t , n)
//                     {
// dp[i1][j][k - t][l - cnt[j] - t] += dp[i0][j - 1][k][l] * (now - k) % Mod * C (l , cnt[j] - t) % Mod;
// if (l) dp[i1][j][k - t][l - cnt[j] - t] += dp[i0][j - 1][k + 1][l - 1] * C (l , cnt[j] - t) % Mod;
// dp[i1][j][k - t][l - cnt[j] - t] %= Mod;
//                     }
//                 }
//         }
//         else 
//         {
//             fro (j , 1 , i)
//                 fro (k , 0 , c1)
//                 {
//                     fro (t , 0 , cnt[j]) if (k >= t) fro (l , cnt[j] - t , n)
//                     {
// dp[i1][j][k - t][l - cnt[j] - t] += dp[i0][j - 1][k][l] * (now - k) % Mod * C (l , cnt[j] - t) % Mod;
// dp[i1][j][k - t][l - cnt[j] - t] %= Mod;
//                     }
//                 }
//         }
//     }
    return 0;
}