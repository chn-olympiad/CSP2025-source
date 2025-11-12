#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int t,n;
ll a[N][4];
int checkx[4]={0};
ll ans;
void Dfs(ll sum,ll cnt)
{

    if(cnt==n+1)
    {
        ans=max(sum,ans);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(checkx[i]>=(n/2)) continue;
        checkx[i]++;
        Dfs(sum+a[cnt][i],cnt+1);
        checkx[i]--;

    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t)
    {
        memset(checkx,0,sizeof(checkx));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
        Dfs(0,1);
        printf("%lld\n",ans);
        ans=0;
        t--;
    }
    return 0;
}
