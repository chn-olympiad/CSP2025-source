#include<bits/stdc++.h>
#define N 1000010
#define INF 1e9
using namespace std;
int n, m, k;
int tmp=0, head[N];
int vis[N];
long long ans=0;
struct edge{
    int to, next;
    long long w;
}e[N<<3];
struct node{
    int to; long long w;
    bool operator < (const node &u) const{
        return u.w < w;
    }
};
priority_queue<node> q;
inline int read(){
    char ch=getchar(); int x=0, f=1;
    while(!isdigit(ch)) {f=(ch=='-')?-1:1; ch=getchar();}
    while(isdigit(ch)) {x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
void add(int u, int v, long long w){
    e[++tmp] = (edge){v, head[u], w};
    head[u] = tmp;
}
void Prim(int s){
    int sum=1; vis[s] = 1;
    q.push((node){s, 0});
    while(!q.empty()){
        node u=q.top();
        while(vis[u.to]&&!q.empty())
            q.pop(), u=q.top();
        if(!vis[u.to]){
            vis[u.to] = 1;
            sum++;
            ans += u.w;
        }
        for(int i=head[u.to]; i; i=e[i].next){
            int v = e[i].to;
            if(!vis[v]) q.push((node){v, e[i].w});
        }
        if(sum == n+k) return ;
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n=read(); m=read(); k=read();
    for(int i=1; i<=m; i++){
        int u=read(), v=read();
        long long w=read();
        add(u, v, w);
        add(v, u, w);
    }
    for(int i=1; i<=k; i++){
        long long c=read();
        for(int j=1; j<=n; j++){
            long long w=read();
            add(n+i, j, w);
            add(j, n+i, w);
        }
    }
    Prim(1);
    printf("%lld", ans);
    return 0;
}
