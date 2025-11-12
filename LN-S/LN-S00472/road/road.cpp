#include<bits/stdc++.h>
using namespace std;
int n, m, k;
const int N = 1e4+7;
struct node{
    int to, val;
};
bool st[N];
struct nodes{
    int u, to, val;
    bool operator < (const nodes &b) const{
        return val > b.val;
    }
};
int gg[20][N];
vector<node> g[N];
vector<node> ggg[N];
priority_queue<nodes> q;
int ans;
nodes ansbian[N];
int cnts = 0;
void solve(){
    q.push({0,1,0});
    while(!q.empty()){
        nodes t = q.top();
        q.pop();
        int ver = t.to, w = t.val;
        if(st[ver]) continue;
        //cout << t.u << " " <<ver << " " << w << endl;
        st[ver] = true;
        if(t.u!=0){
            ggg[t.u].push_back({ver,w});
            ggg[ver].push_back({t.u,w});
        }
        ansbian[++cnts].u = t.u;
        ansbian[cnts].to = t.to;
        ansbian[cnts].val = t.val;
        ans+=w;
        for(int i = 0; i < (int)g[ver].size(); i++){
            if(st[g[ver][i].to]) continue;
            q.push({ver,g[ver][i].to,g[ver][i].val});
        }
    }
    return;
}
//bool xz[20];
//int ansbianfuben[N];
bool stt[N];
void dfs(int num, int cikeans){
    if(num==k+1){
        ans = min(ans,cikeans);
        return;
    }
    //xz[num]=0;
    dfs(num+1,cikeans);
    //xz[num]=1;
    int jianqu = -gg[num][0];
    for(int i = 1; i <= n; i++) stt[i] = 0;
    for(int i = 1; i <= cnts; i++){
        int uu = ansbian[i].u, tto = ansbian[i].to, w = ansbian[i].val;
        //ansbianfuben[i] = w;
        if(gg[num][uu]+gg[num][tto]<w){
            //ansbian[i].val = w;
            jianqu+=w-gg[num][uu]-gg[num][tto];
        }
    }
    dfs(num+1,cikeans-jianqu);
    return;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==b) continue;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }// j = 0 biaoshi kaifa suoxu de jiazhi
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            scanf("%d", &gg[i][j]);
        }
    }
    // xian pao zuixiaoshengchengshu ran hou dfsbianlishifouxuyaokaicheng
    solve();
    if(k==0){
        cout << ans;
        return 0;
    }
    //cout << endl;
    //cout << ans << "\n";
    dfs(1,ans);
    cout << ans;
    return 0;
}
