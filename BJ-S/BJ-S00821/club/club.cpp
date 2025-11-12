#include <bits/stdc++.h>
using namespace std;

struct st
{
    int a , b , c;
}a[100005];
int n , dp[205][205][205];
int dfs(int n1 , int n2 , int n3)
{
    if(dp[n1][n2][n3]) return dp[n1][n2][n3];
    int x = n1 + n2 + n3;
    x++;
    if(x > n)
        return 0;
    int maxn = 0;
    if(n1 < (n / 2)) maxn = max(maxn , dfs(n1 + 1 , n2 , n3) + a[x].a);
    if(n2 < (n / 2)) maxn = max(maxn , dfs(n1 , n2 + 1 , n3) + a[x].b);
    if(n3 < (n / 2)) maxn = max(maxn , dfs(n1 , n2 , n3 + 1) + a[x].c);
    dp[n1][n2][n3] = maxn;
    return maxn;
}
bool cmp(st x , st y)
{
    return x.a > y.a;
}
int main()
{
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    int t;cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b >> a[i].c;
        int flag1 , flag2;
        flag1 = flag2 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i].b != 0)
                flag1 = 1;
            if(a[i].c != 0)
                flag2 = 1;
        }
        if(n <= 200)
        {
            for(int i = 0; i <= 200; i++)
                for(int j = 0; j <= 200; j++)
                    for(int k = 0; k <= 200; k++)
                        dp[i][j][k] = 0;
            cout << dfs(0 , 0 , 0) << endl;
        }
        else if(!flag1 && !flag2)
        {
            sort(a + 1 , a + n + 1 , cmp);
            int ans = 0;
            for(int i = 1; i <= n / 2; i++) ans += a[i].a;
            cout << ans << endl;
        }
        else
        {
            sort(a + 1 , a + n + 1 , cmp);
            int ans = 0;
            for(int i = 1; i <= n / 2; i++) ans += a[i].a;
            for(int i = n / 2 + 1; i <= n; i++) ans += a[i].b;
            cout << ans << endl;
        }
    }
    return 0;
}
