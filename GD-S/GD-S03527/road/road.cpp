#include<bits/stdc++.h>
#define int long long
#define maxn 5000006
using namespace std;

int read(){
    int f = 1,k = 0;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -f;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        k = (k<<1)+(k<<3)+c-48;
        c = getchar();
    }
    return k*f;
}

struct Edge{
    int u,v,w;
    bool operator<(const Edge x) const{
        return w < x.w;
    }
}edge[maxn];

vector<Edge> ste,ade;
int n,m,k,ans = LONG_LONG_MAX,cnt = 0,res = 0,tag = 0;
int fa[maxn],mp[12][maxn],a[12];
bool vis[maxn];

int findx(int x){
    return fa[x] == x ? x : fa[x] = findx(fa[x]);
}

void kruskal(){
    int num = 0;
    cnt = 0;
    for(int i = 1;i <= n+k;i++) fa[i] = i;
    for(int i = 1;i <= n;i++) vis[i] = 0;
    int sum = res;
    ste.clear();
    for(int i = 1;i <= m;i++) ste.push_back(edge[i]);
    for(Edge e:ade){
        ste.push_back(e);
    }
    sort(ste.begin(),ste.end());
    for(Edge e:ste){
        if(num >= n+tag) break;
        int u = e.u,v = e.v,w = e.w;
        if(!vis[u]){
            vis[u] = true;
            num++;
        }
        if(!vis[v]){
            vis[v] = true;
            num++;
        }
        int fu = findx(u),fv = findx(v);
        if(fu == fv) continue;
        cnt++;
        fa[fv] = fa[fu];
        sum += w;
    }
    ans = min(ans,sum);
    return;
}

void dfs(int step){
    if(step > k){
        kruskal();
        // cout << ans << endl;
        return;
    }
    dfs(step+1);
    res += a[step];
    tag++;
    for(int i = 1;i <= n;i++){
        ade.push_back(Edge{i,n+step,mp[step][i]});
    }
    dfs(step+1);
    tag--;
    res -= a[step];
    for(int i = 1;i <= n;i++) ade.pop_back();
    return;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = read();m = read();k = read();
    if(k == 0){
        for(int i = 1;i <= m;i++){
            edge[i].u = read();edge[i].v = read();edge[i].w = read();
        }
        kruskal();
        cout << ans << endl;
    }else{
        for(int i = 1;i <= n;i++) fa[i] = i;
        for(int i = 1;i <= m;i++){
            edge[i].u = read();edge[i].v = read();edge[i].w = read();
        }
        for(int i = 1;i <= k;i++){
            a[i] = read();
            for(int j = 1;j <= n;j++){
                mp[i][j] = read();
            }
        }
        // cout << a[1] << endl;
        dfs(1);
        cout << ans << endl;
    }
    


    return 0;
}

/*
5 5 1
1 2 9
2 3 4
3 4 6
4 5 3
5 1 1
1 4 3 8 1 2



*/