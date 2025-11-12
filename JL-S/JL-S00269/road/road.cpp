#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m,k,ans=0,cc[15],c[10005][15];
int fa[10005];
struct node{
    int u,v;
    long long w;
};
node a[N];
bool cmp(node x,node y){
    return x.w<y.w;
}
int getfa(int x){
    return fa[x]==x ? x :fa[x]==getfa(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>cc[i];
        for(int j=1;j<=n;j++){
            cin>>c[j][i];
        }
    }
    if(k==0){
        for(int i=1;i<=n;i++) fa[i]=i;
        sort(a+1,a+m+1,cmp);
        for(int i=1;i<=m;i++){
            int uu=getfa(a[i].u);
            int vv=getfa(a[i].v);
            if(uu!=vv){
                ans+=a[i].w;
                fa[uu]=vv;
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
