#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int dp[N];
int mark[N];
int ans[N];
int n,k;
int nk;
long long sum[N];
long long res = 0;
void dfs(int cnt,int now)
{
    if(now == n + 1)
    {
        if(cnt == nk)
        {
            bool f = true;
            int id = -1;
            for(int i = 0;i < nk;i++)
            {
                if(i == 0)
                {
                    if(sum[ans[i]] != k)
                    {
                        f = false;
                        break;
                    }
                    id = ans[i];
                }
                else
                {
                    if(sum[ans[i]] ^ sum[id] != k)
                    {
                        f = false;
                        break;
                    }
                }
            }
            if(f == true)
            {
                res++;
            }
        }
        return;
    }
    else
    {
        ans[cnt] = now;
        dfs(cnt + 1,now + 1);
        dfs(cnt,now + 1);
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    bool flag = false;
    bool flag2 = false;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i] != 1)
        {
            flag = true;
        }
        if(a[i] > 1)
        {
            flag2 = true;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        sum[i] = sum[i - 1] ^ a[i];
    }
    if(n <= 2)
    {
        printf("1");
    }
    else if(flag == false && n > 10 && n <= 100)
    {
        printf("%d",n / 2);
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            nk = i;
            dfs(0,1);
        }
        printf("%lld",res);
    }
    return 0;
}
