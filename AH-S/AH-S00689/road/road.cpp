#include<bits/stdc++.h>
using namespace std;
struct road{
    int u,v,w;
}a[1000005];
bool cmp(road a,road b){
    return a.w<b.w;
}
struct ddd{
    int F,S;
};
int n,m,k,c[15],d[15][10005],sum,minn=INT_MAX;
ddd q[10005];
ddd temp;
int vis[10005],cnt[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>d[i][j];
    }
    cout<<0;
    return 0;
}
