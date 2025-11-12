#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k;
struct node{
    int num;
    int wi;
}c[N][N];
struct edge{
    int w2;
}a[N][N];
int city[N];
int spend=0;
int ans=0;
int main(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j].wi=0x3f;
            a[i][j].w2=0x3f;
        }
    }
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        c[u][v].num=c[v][u].num=i;
        c[v][u].wi=w;
        c[u][v].wi=w;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&city[i]);
        for(int j=1;j<=n;j++){
            int w;
            scanf("%d",&w);
            a[i][j].w2=w;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j].w2<c[i][j].wi){
                ans+=a[i][j].w2;
            }else{
                ans+=c[i][j].wi;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
