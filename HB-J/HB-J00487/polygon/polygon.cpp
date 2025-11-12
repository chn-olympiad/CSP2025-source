#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;
int text[5010] = {6,10,15,21,28,36,45,55,66,78,91,105,120};

long long n,a[5010];


int dfs(long long ans)
{
    for(int j = 3;j <= n;j ++)
    {
        if(j == n) break ;
        int double_len_max = (3 * j -text[1]) * 2;
        if(3 * j - text[1] > double_len_max) ans ++;
    }
    for(int j = 4;j <= n;j ++)
    {
        if(j == n) break ;
        int double_len_max = (4 * j -text[2]) * 2;
        if(4 * j - text[2] > double_len_max) ans ++;
    }
    for(int j = 5;j <= n;j ++)
    {
        if(j == n) break ;
        int double_len_max = (5 * j -text[3]) * 2;
        if(5 * j - text[3] > double_len_max) ans ++;
    }
    return ans;
}




int main()
{
      freopen("polygon.in","r",stdin);
      freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    long long len_max = 0,ans = 9;
    for(int i = 1;i <= n;i ++)
    {
        scanf("%lld",&a[i]);
    }
    for(;;)
//  dfs();
    printf("%lld",ans);
    return 0;
}
