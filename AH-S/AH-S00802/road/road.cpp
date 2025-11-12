#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
    int from,to,w;
}a[N];
int n,m,k,c[15][N];
bool v[N],vis[15];
bool cmp(node x,node y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[i].from=u;
        a[i].to=v;
        a[i].w=w;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i][0]);
        for(int j=1;j<=n;j++){
            scanf("%d",&c[i][j]);
        }
    }
    sort(a+1,a+1+m,cmp);
    int ans=0;
    for(int i=1;i<=m;i++){
        int x=a[i].from,y=a[i].to,w=a[i].w;
        if(!v[x]||!v[y]){
            int s=w,id;
            ans+=s;
            v[x]=true;
            v[y]=true;
        }
    }
    cout<<ans;
    return 0;
}
