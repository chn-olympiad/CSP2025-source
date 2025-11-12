#include <bits/stdc++.h>
using namespace std;
struct road{
    long long u,v,w;
};
bool cmp(road a,road b){
    return a.w<b.w;
}
long long n,m,k,a[15][10005],c[15],sum,cnt;
bool vis[10005];
vector<road> e;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool f=true;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        e.push_back((road){u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin >> c[i];
        if(c[i]!=0)f=false;
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j]!=0)f=false;
        }
    }
    if(f==true){
        cout << 0;
        return 0;
    }
    sort(e.begin(),e.end(),cmp);
    cnt=2;
    vis[e[0].u]=1;
    vis[e[0].v]=1;
    sum+=e[0].w;
    for(int i=1;i<e.size()&&cnt<n;i++){
        if(vis[e[i].u]==0){
            cnt++;
            vis[e[i].u]=1;
            sum+=e[i].w;
        }
        if(vis[e[i].v]==0){
            cnt++;
            vis[e[i].v]=1;
            sum+=e[i].w;
        }
    }
    cout << sum;
    return 0;
}
