#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){s=s*10+ch-'0';ch=getchar();}
    return s*w;
}
struct Edge{
    int u,v;long long w;
    Edge(int u, int v, long long w) : u(u), v(v), w(w) {}
    bool operator<(const Edge& other)const{
        return w<other.w;
    }
};
class UnionFind{
private:
    vector<int> parent,rank;
public:
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int x){
        if(parent[x]!=x)parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unite(int x,int y) {
        int rootX=find(x),rootY=find(y);
        if(rootX==rootY)return 0;
        if(rank[rootX]<rank[rootY])parent[rootX]=rootY;
        else if(rank[rootX]>rank[rootY])parent[rootY]=rootX;
        else parent[rootY]=rootX,rank[rootX]++;
        return 1;
    }
};
long long kruskal(int n,vector<Edge>& edges) {
    sort(edges.begin(),edges.end());
    UnionFind uf(n);
    long long total=0;int count=0;
    for(const auto& edge:edges){
        if(uf.unite(edge.u,edge.v)){
            total+=edge.w,count++;
            if (count==n-1)break;
        }
    }return (count==n-1)?total:LLONG_MAX;
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read(),m=read(),k=read();
    vector<Edge>o;
    for(int i=0;i<m;i++){
        int u=read(),v=read();long long w=read();
        o.emplace_back(u-1,v-1,w);
    }vector<long long>c(k);
    vector<vector<long long>>a(k,vector<long long>(n));
    for(int i=0;i<k;i++){
        c[i]=read();
        for(int j=0;j<n;j++)a[i][j]=read();
    }long long ans=LLONG_MAX;
    for (int mask=0;mask<(1<<k);mask++){
        vector<Edge>edges=o;
        long long Cost=0;int node=n;
        for(int i=0;i<k;i++){
            if(mask&(1<<i)){
                Cost+=c[i];
                int town=n+__builtin_popcount(mask&((1<<i)-1));
                for(int city=0;city<n;city++)edges.emplace_back(town,city,a[i][city]);
                node++;
            }
        }long long mstCost=kruskal(node,edges);
        if(mstCost!=LLONG_MAX)ans=min(ans,mstCost+Cost);
    }cout<<ans;
    return 0;
}