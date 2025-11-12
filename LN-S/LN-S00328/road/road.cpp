#include<bits/stdc++.h>
using namespace std;
int k,n,m,f[10005],ans,xy;
struct node{
    int x,y,w;
}v[1000005];
bool cmp(node x,node y){
    return x.w<y.w;
}
int c[15],ak[15][10005];
bool ts=1;
int R(int x){
    if(f[x]==x)return x;
    return f[x]=R(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i = 1,x,y,z;i<=m;i++){
        cin>>x>>y>>z;
        v[i]={x,y,z};
    }
    sort(v+1,v+n+1,cmp);
    ts=k;
    for(int i = 1;i<=k;i++){
        cin>>c[i];
        if(c[i]!=0)ts=0;
        for(int j = 1;j<=n;j++){
            cin>>ak[i][j];
            if(ak[i][j]!=0)ts=0;
        }
    }
    if(ts){
        cout<<0;
        return 0;
    }
    for(int i = 1;i<=n;i++)
            f[i]=i;
    xy=n;
    for(int i = 1;i<=m;i++){
        if(R(v[i].x)!=R(v[i].y)){
            ans+=v[i].w;
            f[R(v[i].x)]=f[R(v[i].y)];
        }
    }
    cout<<ans<<endl;
    return 0;
}
