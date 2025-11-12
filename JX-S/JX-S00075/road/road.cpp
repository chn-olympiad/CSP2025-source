#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,dis[20][15000],co[20],fa[15000],ark,l,r,cnt;
long long ans=0x3f3f3f3f3f3f3f3f,midans,midcnt,sumc;
pair<int,pair<int,int> > ve[1919810],mid;
int findfa(int u)
{
    if(fa[u]==u)return u;
    return (fa[u]=findfa(fa[u]));
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        ve[i]={c,{a,b}};
    }
    for(int i=1;i<=k;i++)
    {
        cin>>co[i];
        for(int j=1;j<=n;j++)cin>>dis[i][j];
    }
    sort(ve+1,ve+m+1),ark=m,cnt=n-1;
    for(int i=0;i<=k;i++)
    {
        midans=sumc;
        if(i>0)
        {
            for(int j=1;j<=n;j++)ve[ark+j]={dis[i][j],{j,cnt+5}};
            midans+=co[i];
            sort(ve+ark+1,ve+ark+n+1);
        }
        l=1,r=((i==0)?(ark+n+1):(ark+1)),midcnt=((i==0)?cnt:(cnt+1));
        for(int j=1;j<=midcnt+100;j++)fa[j]=j;
        while(midcnt>0)
        {
            if(r<=ark+n and (ve[r]<ve[l] or l>ark))mid=ve[r],r++;
            else if(l<=ark)mid=ve[l],l++;
            if(findfa(mid.second.first)==findfa(mid.second.second))continue;
            fa[findfa(mid.second.first)]=mid.second.second,midcnt--,midans+=mid.first;
        }
        if(midans<ans)ans=midans,ark=ark+((i==0)?0:n),sort(ve+1,ve+ark+1),cnt=((i==0)?cnt:(cnt+1)),sumc+=co[i];
    }
    cout<<ans;
    return 0;
}
