#include <bits/stdc++.h>
#define tpi tuple<int,int,int>
#define int long long
using namespace std;
int n,m,k,ans;
tpi e[1000015];
int co[15][10015];
int fa[1000015];
priority_queue<tpi,vector<tpi>,greater<tpi>> tmpq;

int find(int x){while(fa[x]!=x) x=fa[x];return x;}
void merge(int u,int v){fa[find(v)]=find(u);}
int kru(int c){
    priority_queue<tpi,vector<tpi>,greater<tpi>> q;
    for(int i=1;i<=n;i++) fa[i]=i;
    q=tmpq; int res=0,cnt=n-1;
    for(int i=1;i<=k;i++)
        if(c&(1<<i-1)){
            res+=co[i][0]; cnt++; fa[i+n]=i+n;
            for(int j=1;j<=n;j++)
                q.push({co[i][j],n+i,j}),
                q.push({co[i][j],j,n+i});
        }
    while(cnt){
        auto [c,u,v]=q.top();
        q.pop();
        if(find(u)==find(v)) continue;
        merge(u,v);
        res+=c;
        cnt--;
    }
    return res;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,c; cin>>u>>v>>c;
        e[i]={c,u,v};
        e[i]={c,v,u};
        tmpq.push(e[i]);
    }
    for(int i=1;i<=k;i++){
        cin>>co[i][0];
        for(int j=1;j<=n;j++) cin>>co[i][j];
    }
    ans=0x7fffffffffffffff;
    for(int i=0;i<1<<k;i++)
        ans=min(ans,kru(i));
    cout<<ans;
    return 0;
}
