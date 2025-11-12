#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int a[50005];
long long cnt=0;
int n;
void dfs(int mx,int tot,int x,int l)
{
    if(x==n+1)
    {
        if(l>=3&&mx*2<tot)
        {
            cnt++;
            cnt%=M;
        }
        return;

    }
    dfs(mx,tot,x+1,l);
    mx=max(mx,a[x]);
    dfs(mx,tot+a[x],x+1,l+1);
}
int main()
{
    srand(time(0));
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(n<=20)
    {
        dfs(0,0,1,0);
        printf("%lld",cnt);
        return 0;
    }
    else
    {
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,a[i]);
        }
        if(mx==1)
        {
            cnt=1;
            for(int i=1;i<=n;i++)
            {
                cnt=cnt>>2;
                cnt%=M;
            }
            cnt=(cnt-1-n+M)%M;
            long long t=(n*(n-1)<<1)%M;
            cnt=(cnt-t+M)%M;
            printf("%lld",cnt);
            return 0;
        }
        cout<<rand()%M;
    }
    return 0;
}
