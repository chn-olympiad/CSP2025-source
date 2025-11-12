#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[10013];
int a[10013];
int c[13];
struct road{
    int u,v,w;
};
bool cmp(road a,road b){
    return a.w<b.w;
}
int find(int a){
    if(f[a]==a){
        return a;
    }
    return f[a]=find(f[a]);
}
vector<road>g;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.push_back((road){u,v,w});
    }
    for(int i=1;i<=k;i++){
            cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[j];
            for(int l=1;l<j;l++){
                g.push_back((road){j,l,a[l]+a[j]});
            }
        }
    }
    int ans=0;
    sort(g.begin(),g.end(),cmp);
    int cnt=1;
    for(int i=0;i<g.size();i++){
        int fu=find(g[i].u);
        int fv=find(g[i].v);
        if(fu!=fv){
            ans+=g[i].w;
            f[fu]=fv;
            cnt++;
        }
        if(cnt==n){
            break;
        }
        }
        for(int i=1;i<=k;i++){
            ans+=c[i];
        }
        cout<<ans;
    return 0;
}
