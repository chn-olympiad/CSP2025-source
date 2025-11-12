#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n,m,k;
struct node{
    int u,v,w;
}e[N],g[N];
int f[N];
vector<long long> vil[20];
vector<long long> svil[20];
int val[25];
bool vis[25];
bool cmp(node x,node y){
    return  x.w < y.w;
}
int find_f(int x){
    if(f[x] == x){return x;}
    return f[x] = find_f(f[x]);
}
int cnt;
long long ans;
long long mina;
vector<int>vec;
long long maxrd = -1;long long rd = 0;
int ind[10005];
void solve(){
    rd = 0;
    vec.clear();
    for(int i = 1;i <= k;i++){
        if(vis[i] == 1){
            vec.push_back(i);
            rd -= val[i];
        }
    }
    if(!vec.size()){return;}
    for(int i = 1;i <= cnt;i++){
        int eu = g[i].u,ev = g[i].v;

        int lk;
        if(ind[eu] == 1) lk = eu;
        else{lk = ev;}
        bool flag = 0;mina = 2e18;
        for(int j : vec){
            for(int l = 1;l < (int)svil[l].size();l++){
                int p = svil[j][l];
                if(p == vil[j][lk] && !flag){flag = 1;continue;}

                mina = min(mina,p + vil[j][lk]);
                break;
            }
        }
        if(mina < g[i].w){rd += g[i].w - mina;}
    }

    maxrd = max(maxrd,rd);
    return;
}

void dfs(int x){
    if(x > k){
        solve();
        return;
    }
    vis[x] = 1;
    dfs(x + 1);
    vis[x] = 0;
    dfs(x + 1);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for(int i = 1;i <= k;i++){
        int x;
        scanf("%d",&val[i]);
        vil[i].push_back(-1);
        svil[i].push_back(-1);
        for(int j = 1;j <= n;j++){
            scanf("%d",&x);
            vil[i].push_back(x);
            svil[i].push_back(x);
        }
        sort(svil[i].begin(),svil[i].end());

    }
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
    sort(e + 1,e + m + 1,cmp);
    for(int i = 1;i <= m;i++){
        int eu = find_f(e[i].u);
        int ev = find_f(e[i].v);
        if(f[eu] != ev){
            f[eu] = ev;
            cnt++;
            g[cnt] = e[i];
            ans += e[i].w;
            if(cnt == n - 1){
                break;
            }
        }
    }
    if(k == 0){
        cout << ans;
        return 0;
    }
    for(int i = 1;i <= m;i++){
        ind[g[i].u]++;
        ind[g[i].v]++;
    }
    dfs(1);
    cout << ans - maxrd - 1;
    return 0;
}
