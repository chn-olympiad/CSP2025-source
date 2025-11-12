#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

inline void read(int &x){
    x=0;bool f=false;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=true;c=getchar();}
    while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    x=f?-x:x;return ;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>10) write(x/10);
    putchar('0'+x%10);
    return ;
}
inline void print(int x){write(x);putchar('\n');}

const int N = 1.3e5 + 10, M = 2e6 + 10;
const int K = 20, inf = 1e18;

int n, m, k;
struct E{
    int u, v, w;
}e[M], b[N];
int fa[N], siz[N];
int d[K][N], p[K];
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y){
    x = find(x);y = find(y);
    if(siz[x] > siz[y]) swap(x, y);
    fa[x] = y;siz[y] += x;
}

int lt;
bool cmp(E x, E y){return x.w < y.w;}
int ans, cl[N], col;
void Kru(int flag, int sum){col++;
    for(int i = 1; i <= n + k; i++) fa[i] = i, siz[i] = 1;
    sort(e + 1, e + lt + 1, cmp);
    int top = 0, res = sum, w = 0;
    for(int i = 1; i <= lt; i++){
        int x = e[i].u, y = e[i].v;
        if(find(x) == find(y)) continue;
        if(cl[x] != col && x <= n) w++;cl[x] = col;
        if(cl[y] != col && y <= n) w++;cl[y] = col;
        merge(x, y);res += e[i].w;if(flag == 1)b[++top] = e[i];
        if(w == n) break;
    }
    if(flag == 1) lt = top;ans = min(ans, res);
}
bool tag[N];

void dfs(int x, int sum){
    if(x > k){
        int top = lt;
        for(int i = 1; i <= k; i++){
            if(tag[i] == 0) continue;
            for(int j = 1; j <= n; j++) e[++lt] = {n + i, j, d[i][j]};
        }
        Kru(0, sum);
        for(int i = 1; i <= lt; i++) e[i] = b[i];lt = top;return ;
    }
    tag[x] = 1;dfs(x + 1, sum + p[x]);
    tag[x] = 0;dfs(x + 1, sum);
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n);read(m);read(k);
    for(int u, v, w, i = 1; i <= m; i++) read(e[i].u), read(e[i].v), read(e[i].w);
    ans = inf;lt = m;Kru(1, 0);
    for(int i = 1; i <= lt; i++) e[i] = b[i];
    for(int i = 1; i <= k; i++){
        read(p[i]);
        for(int j = 1; j <= n; j++) read(d[i][j]);
    }
    dfs(1, 0);print(ans);
    return 0;
}