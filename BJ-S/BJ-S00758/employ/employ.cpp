#include <bits/stdc++.h>
using namespace std ;
#define int long long
const int mod = 998244353 ;
int a[505] , n , maxn , ans , m , box[505] , c[505];
string s ;
void dfs(int step)
{
    if(step > n)
    {
        int temp = 0 ;
        for(int i = 1 ; i <= n ; i ++)
        {
            if(temp >= c[i]) 
                temp ++ ;
            else if(s[i - 1] == '0')
                temp ++ ;
        }
        if(n - temp >= m)
            ans ++ ;
        return ; 
    }
    for(int i = a[0] ; i <= a[n] ; i ++)
    {
        if(box[i])
        {
            c[step] = i ;
            box[i] -- ;
            dfs(step + 1) ;
            box[i] ++ ;
        }
    }
}
signed main() 
{
    freopen("employ.in" , "r" , stdin) ;
    freopen("employ.out" , "w" , stdout) ;
    cin >> n >> m ;
    cin >> s ;
    int k = 0 ;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i] ;
        box[a[i]] ++ ;
        maxn = max(maxn , a[i]) ;
    }
    sort(a + 1 , a + n + 1) ;
    for(int i = 0 ; i < s.size(); i ++)
        k += s[i] ;
    if(k == n)
    {
        long long ans = 1 ;
        for(int i = 1 ; i <= n ; i ++)
        {
            ans = (ans * i) % mod;
        }
        cout << ans << endl;
    }
    else 
    {
        if(n <= 18)
        {
            dfs(1) ;
            for(int i = 1 ; i <= n ; i ++)
                box[i] = 0 ;
            for(int i = 1 ; i <= n ; i ++)
                box[a[i]] ++ ;
            for(int i = 1 ; i <= n ;i ++)
            {
                long long g = 1 ;
                for(int j = 1 ; j <= box[i] ; j ++)
                {
                    g = (g * j) % mod ;
                }
                ans = (ans * g) % mod ;
            }
            cout << ans % mod << endl;
        }
        else if(m == 1)
        {
            if(a[1] == 0)
            {
                int ans = 1 ;
                for(int i = 1 ; i <= n - 1 ; i ++)
                {
                    ans = (ans * i) % mod ;
                }
                cout << ans << endl;
            }
            else 
            {
                int ans = 1 ;
                for(int i = 1 ; i <= n ; i ++)
                {
                    ans = (ans * i) % mod ;
                }
                cout << ans << endl;
            }
        }
        else if(m == n)
        {
            cout << 1 << endl;
        }
    }
    return 0 ;
}