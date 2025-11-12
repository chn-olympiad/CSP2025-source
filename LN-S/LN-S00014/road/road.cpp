#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[105][105],fa[10005];
long long ans;
struct node{
    int u,v,w;
}b[1000005];
bool cmp(node x,node y){
    return x.w<y.w;
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void join(int x,int y){
    int q=find(x),w=find(y);
    if(q!=w)fa[x]=w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=0x7f7f7f7f;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=z;
        a[y][x]=z;
    }
    for(int i=1;i<=k;i++){
        int x,y[105];
        cin>>x;
        for(int j=1;j<=n;j++){
            cin>>y[j];
            for(int k=1;k<j;k++)a[k][j]=a[j][k]=min(a[j][k],x+y[j]+y[k]);
        }
    }
    m=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            m++;
            b[m].u=i;
            b[m].v=j;
            b[m].w=a[i][j];
        }
    }
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(find(b[i].u)!=find(b[i].v)){
            join(b[i].u,b[i].v);
            ans+=b[i].w;
           // cout<<b[i].u<<' '<<b[i].v<<' '<<b[i].w<<' '<<ans<<endl;
        }
    }
    cout<<ans;
    return 0;
}
