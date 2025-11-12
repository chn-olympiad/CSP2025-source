#include<bits/stdc++.h>
using namespace std;
const int N=500005;
struct Node
{
    int from,to,w;
};
bool cmp(Node x,Node y){
    return x.w<y.w;
}
Node edge[N];
int n,m,k,ans,fa[N],con[5005][5005];
void init(){
    for(int i=1;i<=n;i++) fa[i]=i;
    return ;
}
int get(int x){
    if(fa[x]==x) return fa[x];
    return fa[x]=get(fa[x]);
}
void unit(int x,int y){
    x=get(x),y=get(y);
    if(x!=y) fa[x]=y;
    return ;
}
void Kruskal(){
    for(int i=1;i<=m;i++){
        int u=edge[i].from;
        int v=edge[i].to;
        int w=edge[i].w;
        if(get(u)!=get(v)){
               // cout<<u<<' '<<v<<" "<<w<<endl;
            ans+=w;
            unit(u,v);
        }
    }
    return ;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        edge[i].from=t1;
        edge[i].to=t2;
        edge[i].w=t3;
    }
    int top=m;
    for(int i=1;i<=k;i++){
        int no;
        cin>>no;
        for(int j=1;j<=n;j++){
            int temp;
            cin>>temp;
            con[i][j]=temp;
        }
    }
    k--;
    for(int z=1;z<=k;z++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                edge[++top].from=i;
                edge[top].to=j;
                edge[top].w=con[k][i]+con[k][j];
            }
        }
    }
    sort(edge+1,edge+top+1,cmp);
    for(int i=1;i<=top;i++){
        cout<<edge[i].from<<" "<<edge[i].to<<" "<<edge[i].w<<endl;
    }
    Kruskal();
    cout<<ans;
    return 0;
}
