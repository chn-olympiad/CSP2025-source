#include <bits/stdc++.h>
using namespace std;
struct p{
    int u,v,w,r;
}a[5000000];
int fa[5000000],vall[5000000][2],n;
bool cmp(p x,p y){
    if(x.u>n&&vall[x.r][0])  x.w+=vall[x.r][1];
    if(y.u>n&&vall[y.r][0])  y.w+=vall[y.r][1];
    return x.w<y.w;
}
int find(int x){
    if(x==fa[x])  return x;
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,k,t=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[++t].u>>a[t].v>>a[t].w;
    }
    for(int i=1;i<=k;i++){
        cin>>vall[i][1];
        vall[i][0]=1;
        for(int j=1;j<=n;j++){
            cin>>a[++t].w;
            a[t].u=i+n,a[t].v=j,a[t].r=i;
        }
    }
    sort(a+1,a+t+1,cmp);
    for(int i=1;i<=n+k;i++)  fa[i]=i;
    long long ans=0;
    int eg=0;
    for(int i=1;i<=t;i++){
        int x=find(a[i].u),y=find(a[i].v);
        if(x==y)  continue;
        fa[x]=y;
        eg++;
        ans+=a[i].w;
        if(a[i].u>n&&vall[a[i].r][0]){
            ans+=vall[a[i].r][1];
            vall[a[i].r][0]=0;
            eg--;
            if(vall[a[i].r][1])  (a+i,a+t+1,cmp);
        }
        //cout<<ans<<' ';
        if(eg==n-1)  break;
    }
    cout<<ans;
    return 0;
}
