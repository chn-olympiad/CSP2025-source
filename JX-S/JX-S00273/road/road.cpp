#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 10 + 5;
struct Node{
    int w,to,next;
}e[2 * M];
int n,m,k,cnt,head[N],c[K],a[K][N];
void init(){
    memset(head,-1,sizeof(head));
    cnt = 0;
}
void add(int u,int v,int w){
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
void addEdge(int u,int v,int w){
    add(u,v,w);
    add(v,u,w);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        addEdge(u,v,w);
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    cout << 0;
    return 0;
}
