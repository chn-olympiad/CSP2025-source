//remember:
//freopen!!!
//mod!!!
//time limit and memory limit!!!
//the special numbers!!!

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N=1e5+10,M=2e6+10;
int n,m,k,tot,cnt,ans;
int f[N];
vector<pii> e[N];
struct node{
    int u,v,w;
}a[M];
map<pii,pii> mp;
bool cmp(node x,node y){
    return x.w<y.w;
}
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void kruskal(){
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        auto [u,v,w]=a[i];
        int x=find(u),y=find(v);
        if(x==y)
            continue;
        ans+=w;
        f[x]=y;
        if(++tot==n+k-1)
            return;
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(u>v)
            swap(u,v);
        if(mp[{u,v}].second)
            mp[{u,v}]={min(mp[{u,v}].first,w),1};
        else
            mp[{u,v}]={w,1};
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        mp[{i,n+i}]={x,1};
        for(int j=1;j<=n;j++){
            int y;
            cin>>y;
            if(mp[{i,j}].second){
                int w=mp[{i,j}].first;
                int g=min(w-x,y);
                mp[{j,n+i}]={g,1};
            }else
                mp[{j,n+i}]={y,1};
            mp[{i,j}]={0,0};
        }
    }
    for(auto [x,y]:mp){
        auto [u,v]=x;auto [w,t]=y;
        if(t==1)
        a[++cnt]={u,v,w};
    }
    kruskal();
    cout<<ans<<'\n';
    return 0;
}
