#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int fa[10005],n,m,k,a[20][10005];
int build[105];
int gr[1005][1005];
struct node{
    int from,to,v;
    const bool operator <(const node _) const{
        return v<_.v;
    }
};
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy) fa[fx]=fy;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    vector<node> g;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.pb({a,b,c});
    }
    if(k==0){
        int ans=0,cnt=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        sort(g.begin(),g.end());
        for(int i=0;i<g.size();i++){
            if(find(g[i].from)!=find(g[i].to)){
                merge(g[i].from,g[i].to);
                cnt++,ans+=g[i].v;
                if(cnt==n-1){
                    cout<<ans;
                    return 0;
                }
            }
        }
    }
    else{
        int ans=0,cnt=0;
        for(int i=1;i<=k;i++){
            cin>>build[i];
            ans+=build[i];
            int idx=-1,minn=INT_MAX;
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                if(a[i][j]<minn) minn=a[i][j],idx=j;
            } 
            for(int j=1;j<=n;j++){
                g.pb({idx,j,a[i][j]});
            }
        }
        for(int i=1;i<=n;i++) fa[i]=i;
        sort(g.begin(),g.end());
        for(int i=0;i<g.size();i++){
            if(find(g[i].from)!=find(g[i].to)){
                merge(g[i].from,g[i].to);
                cnt++,ans+=g[i].v;
                if(cnt==n-1){
                    cout<<ans;
                    return 0;
                }
            }
        }
    }
    return 0;
}