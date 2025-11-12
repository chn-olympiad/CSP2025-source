#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
const int N=1e4+25;
vector<pair<int,int> > G[N];
struct Edge{
    int u,v,w;
};
Edge make_edge(int u,int v,int w){
    Edge ans;
    ans.u=u;ans.v=v;ans.w=w;
    return ans;
}
vector<Edge> edge;
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
int fa[N],n,m,k;
int find(int x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
void Union(int x,int y){
    int fx=find(fa[x]),fy=find(fa[y]);
    fa[fx]=fy;
    return;
}
int kru(){
    int cnt=0,ans=0;
    for(vector<Edge>::iterator it=edge.begin();it!=edge.end();it++){
        if(find(it->u)!=find(it->v)){
            Union(it->u,it->v);
            ++cnt;
            ans+=it->w;
            if(cnt==n-1) break;
        }
    }
    return ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
        edge.push_back(make_edge(u,v,w));
        edge.push_back(make_edge(v,u,w));
    }
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=n+1;i<=n+k;i++){
        int curc;
        scanf("%d",&curc);
        for(int j=1;j<=n;j++){
            int curx;
            scanf("%d",&curx);
            G[curc].push_back(make_pair(j,curx+curc));
            G[j].push_back(make_pair(curc,curx+curc));
            edge.push_back(make_edge(curc,j,curx+curc));
            edge.push_back(make_edge(j,curc,curx+curc));
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    printf("%d\n",kru());
    return 0;
}