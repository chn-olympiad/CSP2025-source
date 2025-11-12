#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct abc{
    int u,v,w;
}a[8000005];
int cnt=0;
bool cmp(abc x,abc y){
    return x.w<y.w;
}
bool vis[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[cnt].u=min(u,v);
        a[cnt].v=max(u,v);
        a[cnt].w=w;
        cnt++;
    }
    for(int h=1;h<=k;h++){
        int c;
        cin>>c;
        int sz[n+1];
        for(int i=1;i<=n;i++){
            cin>>sz[i];
            for(int j=1;j<i;j++){
                a[cnt].u=j;
                a[cnt].v=i;
                a[cnt].w=sz[j]+c+sz[i];
                cnt++;
            }
        }
    }
    sort(a,a+cnt,cmp);
    int ans=0;
    for(int i=0;i<cnt;i++){
        if( !vis[a[i].u] || !vis[a[i].v] ){
            ans+=a[i].w;
            vis[a[i].u]=vis[a[i].v]=true;
        }
    }
    cout<<ans;
    return 0;
}
