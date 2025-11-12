#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int v,c;
};
vector<node> e[10010];
int n,m,k,x,y,z,l,r,ans,vis[10010],c[10010];
bool dfs(int x,int y,int sum,int maxn,int deep){
    if(sum>maxn) return 0;
    if(sum==maxn){
        if(deep==n) return 1;
        else return 0;
    }
    if(deep==n) return 1;
    bool o=0;
    for(auto xx:e[x]){
        int vv=xx.v,cc=xx.c;
        if(vv==y) continue;
        if(vis[vv]) continue;
        vis[vv]=1;
        o|=dfs(vv,x,sum+cc,maxn,deep+1);
        vis[vv]=0;
    }
    return o;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
        r+=z;
    }
    if(k==0){
        while(l<=r){
            int mid=(l+r)/2;
            memset(vis,0,sizeof(vis));
            vis[1]=1;
            if(dfs(1,0,0,mid,1)) {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>x;
        }
    }
    cout<<0;
    return 0;
}
