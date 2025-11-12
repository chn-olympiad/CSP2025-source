#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;

int a[5005];
int n;
int ans;
int dp[5005][5005];
long long inv[5005];

long long c(int k,int m)
{
    long long ans1 = 1;
    int cnt = m;
    for(int i = k;i >= k-m+1;i--)
    {
        ans1 *= (long long)i*inv[cnt--];
        ans1 %= p;
    }

    return ans1;
}

void so(int a,int b,int &x,int &y)
{
    if(b == 0) x = 1,y = 0;
    else
    {
        so(b,a%b,y,x);
        y -= a / b * x;
    }
}

void dfs(int x,int cnt,int maxn,int num)
{
    if(x > n)
    {
        if(cnt > maxn*2 && num >= 3)
        {
            ans++;
        }
        return;
    }

    dfs(x+1,cnt+a[x],max(maxn,a[x]),num+1);
    dfs(x+1,cnt,maxn,num);
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    scanf("%d",&n);

    bool flag = 1;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i] != 1) flag = 0;
    }

    if(flag == 0)
    {
        dfs(1,0,0,0);
        cout << ans;
        return 0;
    }

    inv[1] = 1;
    for(int i = 2;i <= 5000;i++)
    {
        int x = 0,y = 0;
        so(i,p,x,y);
        inv[i] = (x+p)%p;
    }

    long long ans = 0;
    for(int i = 3;i <= n;i++)
    {
        ans += c(n,i);
        ans %= p;
    }

    printf("%lld",ans);

    return 0;
}
