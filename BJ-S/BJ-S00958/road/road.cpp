#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 7, M = 1e6 + 7;
int ufs[N << 1];
int u[M << 1], v[M << 1], w[M << 1];
int n, m, k, sum;
int ans = 0, o_ans = INT_MAX;
int cost[20];
vector<int> value[20];
struct edge{
    int next, to, w;
}e[M << 2];
int en = 0, hlist[M << 2];

void add(int u, int v, int w){
    e[++ en].next = hlist[u];
    e[en].to = v;
    e[en].w  = w;
    hlist[u] = en;
}
int find(int u){
    if(u == ufs[u])return u;
    return ufs[u] = find(ufs[u]);
}
void merge(int a, int b){
    ufs[find(a)] = find(b);
}

struct node{
    int u, v, w;
    friend bool operator < (node a, node b) {
        return a.w > b.w;
    }
};
priority_queue<node> p;
void kruskal(int d){
    int num = 0;
    for(int i = 1; i <= m + n * d; i ++){
        int u = p.top().u, v = p.top().v, w = p.top().w;
        //cout<<"u="<<u<<" v="<<v<<"w="<<w<<endl;
        p.pop();
        if(find(u) != find (v)){
            merge(u, v);
            //cout<<" merge"<<u<<" "<<v<<"="<<w<<endl;
            num ++;ans += w;
        }
        //cout<<" num="<<num<<" target="<<n+d-1<<endl;
        if(num == n + d - 1)return;
    }
}
void init(){
    for(int i = 1; i <= n + k; i ++){
        ufs[i] = i;
    }ans = 0, sum = 0;
    while(!p.empty())p.pop();
    for(int i = 1; i <= m; i ++){
        p.push((node){u[i], v[i], w[i]});
    }
}
int main(){
    freopen("road2.in", "r", stdin);
    freopen("road2.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)ufs[i] = i;
    for(int i = 1; i <= m; i ++){
        cin >> u[i] >> v[i] >> w[i];
        add(u[i], v[i], w[i]);
        p.push((node){u[i], v[i], w[i]});
    }
    kruskal(0);//bu jian pao yi bian
    for(int i = 1; i <= k; i ++){
        cin >> cost[i];
        for(int j = 1, v; j <= n; j ++){
            cin >> v;
            value[i].push_back(v);
        }
    }
    o_ans = ans;
    for(int i = 1; i <= (1 << k) - 1; i ++){//mei ju
        init();
        for(int j = 1; j <= 1 << (k - 1); j <<= 1){
            if(i & j){
                sum ++;
                ans += cost[(int)log2(j)+1];
                //cout<<"log2("<<j<<")="<<log2(j)<<endl;
                for(int z = 0; z < n; z ++){
                    p.push((node){sum + n, z + 1, value[(int)log2(j)+1][z]});
                    //cout<<"z = "<<z<<" v[z]="<<value[(int)log2(j)+1][z]<<endl;
                }
            }
        }
        //cout<<"i ="<<i<<endl;
        kruskal(sum);
        o_ans = min(o_ans, ans);
        //cout<<"ans = "<<ans<<endl;
    }
    cout << o_ans;
//    vis[1] = 1;
//    dfs(1);
    return 0;
}
