#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

const int M = 1e6 + 10,N = 1e4 + 10;
struct node{
    int u,v,w;
    node(){}
    node(int u,int v,int w){
        this -> u = u;
        this -> v = v;
        this -> w = w;
    }
    bool operator < (const node &x) const{
        return w<x.w;
    }
}edge[M],e1[N],e2[N];
int s;
int a[15][N];
int father[N];
int find(int x){
    if(x==father[x]) return father[x];
    return father[x] = find(father[x]);
}
void unionn(int a,int b){
    int x = find(a),y = find(b);
    if(x!=y) father[y] = x;
}
void init(int n){
    for(int i=1;i<=n;i++)father[i] = i;
}
ll Krus(int n,int m){
    ll ans = 0;s = 0;
    init(n);
    for(int i=1;i<=m&&s<n-1;i++){
        int u = edge[i].u,v = edge[i].v,w = edge[i].w;
        if(find(u)!=find(v)){
            unionn(u,v);
            ans += w;
            e1[++s] = edge[i];
        }
    }
    return ans;
}
ll ans;
int n,m,k;
void DFS(int id,int cnt,ll base){
    for(int i=id;i<=k;i++){
        for(int j=1;j<=n;j++) e2[j] = node(j,0,a[i][j]);
        sort(e2+1,e2+1+n);
        for(int j=1;j<=n;j++) e2[j].v = e2[1].u;
        int l1 = 0,l2 = 1;
        int j = 0;
        while(l1<s&&l2<n){
            if(e1[l1+1]<e2[l2+1]) edge[++j] = e1[++l1];
            else edge[++j] = e2[++l2];
        }
        while(l1<s) edge[++j] = e1[++l1];
        while(l2<n) edge[++j] = e2[++l2];
        vector<node> ve(n+10);
        for(int x=1;x<=n-1;x++) ve[x] = e1[x];
        ll temp = Krus(n,j)+a[i][0]+e2[1].w+base;
        //cout<<temp<<endl;
        if(ans>temp){
            ans = temp;
            DFS(i+1,cnt+1,a[i][0]+e2[1].w+base);
        }
        for(int x=1;x<=n-1;x++) e1[x] = ve[x];
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge+1,edge+1+m);
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    init(n);
    ans = Krus(n,m);
    DFS(1,0,0);
    cout<<ans;
    return 0;
}
