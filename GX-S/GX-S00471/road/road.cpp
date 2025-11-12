#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn = 1e6+5;
long long ans = 1e18;

struct edge{
    int to;
    int val;
    bool operator > (const edge &e) const{
        return val > e.val;
    }
};

priority_queue<edge, vector<edge>, greater<edge> > pq;
queue<edge> q;

int fa[maxn+10];
int mp[12][maxn];
int d[12];
bool flag[12];
vector<edge> v[maxn+10];

void se(){
    for(int i=1;i<=n;i++) fa[i] = i;
}

int fi(int x){
    if(fa[x] == x) return x;
    return fa[x] = fi(fa[x]);
}

bool ju(){
    int x = fi(1);
    for(int i=1;i<=n;i++){
        if(fi(i) != x) return 0;
    }
    return 1;
}

void kruskal(int num, int x){
    long long cnt = x;
    int c = 0;
    for(int i=1;i<=num;i++){
        int l = v[i].size();
        for(int j=0;j<l;j++) pq.push(v[i][j]);
        while(1){
            if(pq.empty()) break;
            edge e = pq.top();
            if(fi(i) != fi(e.to)){
                if(num > n && flag[e.to]){
                    pq.pop();
                    continue;
                }
                cnt += e.val;
                fa[fi(e.to)] = i;
                c++;
                break;
            }
            pq.pop();
        }
        while(pq.size()) pq.pop();
        if(c >= n-1){
            if(ju()){
                ans = min(ans , cnt);
                return ;
            }
        }
    }
}

void dfs(int x, int dep, int tot){
    if(x > k) return ;
    for(int j=1;j<=n;j++){
        int p = mp[x][j];
        edge a, b;
        a.to = j, a.val = p;
        b.to = n + dep, b.val = p;
        v[n + dep].push_back(a);
        v[j].push_back(b);
    }
    tot += d[x];
    flag[x] = 0;
    se();
    kruskal(n+dep, tot);
    dfs(x+1, dep+1, tot);
    tot -= d[x];
    flag[x] = 1;
    v[n+dep].clear();
    dfs(x+1, dep, tot);
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    int u,t,p;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d", &u, &t, &p);
        edge a, b;
        a.to = t, a.val = p;
        b.to = u, b.val = p;
        v[u].push_back(a);
        v[t].push_back(b);
    }
    if(k == 0){
        se();
        kruskal(n, 0);
        printf("%lld", ans);
        return 0;
    }
    for(int i=1;i<=k;i++){
        scanf("%d", &d[i]);
        for(int j=1;j<=n;j++) scanf("%d", &mp[i][j]);
        flag[n+i] = 1;
    }
    for(int i=n+1;i<=n+k;i++){
        for(int j=1;j<=n;j++){
            edge a, b;
            a.to = j, a.val = p;
            b.to = i, b.val = p;
            v[i].push_back(a);
            v[j].push_back(b);
        }
    }
    se();
    kruskal(n, 0);
    dfs(1, 1, 0);
    printf("%lld", ans);

    return 0;
}
