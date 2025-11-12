#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int fa[10015];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
pair<int,pair<int,int> >ee[1000005],e[10005];
pair<int,int>a[11][10015];
int c[11],st[11],ss;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>ee[i].second.first>>ee[i].second.second>>ee[i].first;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)a[i][j].second=j;
        for(int j=1;j<=n;j++)cin>>a[i][j].first;
        sort(a[i]+1,a[i]+n+1);
    }
    int cnt=0;
    sort(ee+1,ee+m+1);
    for(int i=1;i<=m;i++){
        if(find(ee[i].second.first)==find(ee[i].second.second))continue;
        fa[find(ee[i].second.first)]=find(ee[i].second.second);
        e[++cnt]=ee[i];
    }
    int ans=1e18;
    for(int s=0;s<(1<<k);s++){
        int mg=0,res=0;
        for(int i=1;i<=n+k;i++)fa[i]=i;
        for(int j=1;j<=k;j++)st[j]=1;
        for(int j=1;j<=k;j++){
            if(s&(1<<(j-1)))res+=c[j];
        }
        ss=1;
        while(mg<n-1+__builtin_popcount(s)){
            while(ss<n&&find(e[ss].second.first)==find(e[ss].second.second))ss++;
            int mn=0,ms=e[ss].first;
            if(ss==n)ms=1e18;
            for(int i=1;i<=k;i++){
                if(!(s&(1<<(i-1))))continue;
                while(st[i]<=n&&find(a[i][st[i]].second)==find(i+n))st[i]++;
                if(st[i]<=n&&a[i][st[i]].first<ms){
                    mn=i;ms=a[i][st[i]].first;
                }
            }
            if(mn==0){
                fa[find(e[ss].second.first)]=find(e[ss].second.second);
                res+=e[ss].first;
            }
            else{
                fa[find(a[mn][st[mn]].second)]=find(mn+n);
                res+=a[mn][st[mn]].first;
            }
            mg++;
        }
        ans=min(ans,res);
    }
    cout<<ans;

    return 0;
}
