#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
}v[2000005];
bool cmp(node x,node y){
    return x.w<y.w;
}
int f[10015];
int findf(int x){
    if(f[x]!=x)return findf(f[x]);
    return f[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v[i]={x,y,z};
    }
    for(int i=1;i<=k;i++){
        int c;
        scanf("%d",&c);
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            v[m+(i-1)*n+j]={n+i,j,x};
        }
    }
    m+=n*k;
    n+=k;
    sort(v+1,v+m+1,cmp);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    long long sum=0;
    for(int i=1;i<=m;i++){
        int xfu=findf(v[i].u);
        int xfv=findf(v[i].v);
        if(xfu!=xfv){
            f[xfu]=xfv;
            sum+=v[i].w;
            //cout<<v[i].u<<" "<<v[i].v<<" "<<xfu<<" "<<xfv<<" "<<v[i].w<<" "<<sum<<endl;
        }
    }
    printf("%lld",sum);
    return 0;
}
