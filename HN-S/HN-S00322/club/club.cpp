#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=205;
int n,a[N],b[N],c[N],id[N],dp[M][M][M];
void solve()
{
    cin>>n;
    int res=0,sz1=0,sz2=0,sz3=0,flg=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i],flg|=!!c[i];
        if(a[i]>=b[i]&&a[i]>=c[i])sz1++,res+=a[i];
        else if(b[i]>=a[i]&&b[i]>=c[i])sz2++,res+=b[i];
        else sz3++,res+=c[i];
    }
    if(sz1<=(n/2)&&sz2<=(n/2)&&sz3<=(n/2))return cout<<res<<"\n",void();
    if(!flg)
    {
        res=0;
        for(int i=1;i<=n;i++)id[i]=i,res+=a[i];
        sort(id+1,id+n+1,[](int x,int y){return b[x]-a[x]>b[y]-a[y];});
        for(int i=1;i<=(n>>1);i++)res+=b[id[i]]-a[id[i]];
        return cout<<res<<"\n",void();
    }
    memset(dp,0,sizeof(dp));
    res=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=min(i,n>>1);j++)
            for(int k=0;k<=min(i-j,n>>1);k++)
            {
                if(i-j-k>(n>>1))continue;
                dp[i][j][k]=max((i==j+k?0:dp[i-1][j][k]+a[i]),max((j?dp[i-1][j-1][k]+b[i]:0),(k?dp[i-1][j][k-1]+c[i]:0)));
                res=max(res,dp[i][j][k]);
            }
    cout<<res<<"\n";
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int cas;
    cin >> cas;
    while(cas--) solve();
    return 0;
}