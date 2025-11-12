#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[1000001],s,c,x[1000001],b[11][1000001];
struct node{
    int u,v,w;
}a[1000001];
bool cmp(node x,node y){
    return x.w<y.w;
}
int fin(int x){
    if(f[x]==x)return x;
    return f[x]=fin(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    for(int i=1;i<=k;i++)for(int j=1;j<=n+1;j++)cin>>b[0][0];
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++){
        int u=a[i].u,v=a[i].v;
        if(fin(u)!=fin(v)){
            f[fin(u)]=fin(v);
            s+=a[i].w,c++;
            if(c==n-1){
                cout<<s;
                break;
            }
        }
    }
    return 0;
}
