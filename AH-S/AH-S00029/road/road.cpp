#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 100;
typedef struct Edge{
    int next;
    int to;
    int w;
    int c;
}Edge;
typedef struct MyRule{
    bool operator() (Edge a,Edge b){
        return a.w > b.w;
    }
}MyRule;
Edge edge;
priority_queue<Edge,vector<Edge>,MyRule> que;
map<int,bool> mp;
int fa[N];
int head[N];
int n,m,k;
int cnt;
int ans;
void add(int u,int v,int w,int c){
    edge.c = c;
    edge.to = v;
    edge.w = w;
    edge.next = u;
    que.push(edge);
}
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void un(int x,int y){
    fa[y] = x;
}
bool check(){
    int temp = find(1);
    for(int i = 2;i<=n;i++){
        if(find(i) != temp) return false;
    }
    return true;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i =1;i<=n;i++){
        fa[i] = i;
    }
    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w,0);
        add(v,u,w,0);
    }
    for(int i = 1;i<=k;i++){
        int c,w;
        cin>>c;
        for(int j = 1;j<=n;j++){
            cin>>w;
            add(i+n,j,w+c,c);
            add(j,i+n,w+c,c);
        }
    }
    cnt = 0;
    while(check() == false){
        Edge t = que.top();
        que.pop();
        int fx = find(t.to);
        int fy = find(t.next);
        if(fx != fy){
            if(t.next > n){
                if(mp[t.next] == false){
                    ans -= t.c;
                    mp[t.next] = true;
                }
            }else{
                if(mp[t.to] == false){
                    ans -= t.c;
                    mp[t.to] = true;
                }
            }
            un(fx,fy);
            cnt++;
            ans += t.w;
        }
    }
    cout<<ans<<endl;
    return 0;
}