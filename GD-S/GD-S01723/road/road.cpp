#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int N=1e4+10;
const int M=1e6+10;
const int K=10;
struct node_edge{
    int u,v,w;
}edge_rd[M];
vector<pair<int,int>>edge[N];
int n,m,k,c[N];
int a[K][N];
int fa[N];
bool cmp(node_edge a,node_edge b){
    return a.w<b.w;
}
int find(int x){
    return fa[x]= fa[x]==x?x:find(fa[x]);
}
void kruskal(){
    for(int i=1;i<=n;i++)fa[i]=i;
    int cnt=0,res=0;
    for(int i=1;i<=m;i++){
        int u=find(edge_rd[i].u),v=find(edge_rd[i].v);
        if(u==v)continue;
        cnt++;
        if(cnt==n)break;
        res+=edge_rd[i].w;
        fa[u]=v;
    }
    printf("%lld\n",res);
    return ;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    if(!k){
        for(int i=1;i<=m;i++){
            int u=read(),v=read(),w=read();
            edge_rd[i].u=u;
            edge_rd[i].v=v;
            edge_rd[i].w=w;
        }
        sort(edge_rd+1,edge_rd+m+1,cmp);
        kruskal();
    }else{
        for(int i=1;i<=m;i++){
            int u=read(),v=read(),w=read();
            edge[u].push_back({v,w});
            edge[v].push_back({u,w});
        }
        bool flg=1;
        for(int i=1;i<=k;i++){
            c[i]=read();
            for(int j=1;j<=n;j++){
                a[i][j]=read();
                if(!(c[i]==0&&a[i][j]==0))
                    flg=0;
            }
        }
        if(flg){
            printf("0");
            return 0;
        }
    }
    return 0;
}
