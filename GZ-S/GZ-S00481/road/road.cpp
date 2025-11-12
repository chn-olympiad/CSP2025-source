//GZ-S00481 盘州市第二中学 陈超
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 3000010, M = (1 << 12);
const LL INF = 1e18;

int n, m, k;
LL valu[15];
bool st[15], bk[15], fn[N];
int f[N];
LL ans = INF;
int df[N];
struct node{
    LL u, v, w;
    bool operator<(const node& x){
        return w < x.w;
    }
}e[N];

LL read(){
    LL x = 0;
    char ch;
    ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while('0' <= ch && ch <= '9'){
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}

int find(int x){
    return f[x] = (x == f[x] ? x : find(f[x]));
}

void kruskal(){
    LL res = 0;
    for(int i = 1; i <= k; i++)
        if(st[i]){
            if(bk[i]) return;
            res += valu[i];
        }
    for(int i = 1; i <= n + k; i++) f[i] = i, fn[i] = 0;
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        LL a = e[i].u, b = e[i].v, c = e[i].w;
        if(a > n && !st[a-n]) continue;
        int pa = find(a), pb = find(b);
        if(pa == pb) continue;
        if(a > n && cnt == n && st[a-n]) bk[a-n] = 1;
        f[pa] = pb;
        if(a <= n && !fn[a]) cnt++, fn[a] = 1;
        if(b <= n && !fn[b]) cnt++, fn[b] = 1;
        res += c;
    }
    /*for(int i = 1; i <= k; i++)
        if(st[i]){
            if(df[i] == lst){
                bk[i] = 1;
                break;
            }
        }*/
    ans = min(res, ans);
}

void dfs(int u){
    if(u > k){

    /*for(int i = u; i; i--)
        if(bk[i] && st[i])
            return;*/
        kruskal();
        return;
    }
    df[u] = N;
    st[u] = 1;
    dfs(u + 1);
    df[u] = N;
    st[u] = 0;
    dfs(u + 1);
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    //cin.tie(nullptr)->ios::sync_with_stdio(false);
    n = read(), m = read(), k = read();
    LL maxn = 0;
    for(int i = 1; i <= m; i++){
        LL a, b, c;
        a = read(), b = read(), c = read();
        e[i] = {a, b, c};
        maxn = max(maxn, c);
    }

    for(int i = 1; i<= k; i++){
        valu[i] = read();
        for(int j = 1; j <= n; j++){
            LL x = read();
            if(x >= maxn) continue;
            ++m; e[m].w = x;
            e[m].u = n + i, e[m].v = j;
        }
    }

    sort(e + 1, e + m + 1);
    dfs(1);
    cout << ans;
    return 0;
}
