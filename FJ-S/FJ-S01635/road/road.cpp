#include<bits/stdc++.h>

using namespace std;

template<typename T>
void read(T &x){
    x = 0;
    bool f = 0;
    char c = getchar_unlocked();
    while(c < '0' || c > '9'){
        f |= (c=='-');
        c = getchar_unlocked();
    }
    while('0' <= c && c <= '9'){
        x = x*10+c-'0';
        c = getchar_unlocked();
    }
    if(f) x = -x;
}

const int N = 1e4+99, M = 2e6+99, Q = 11, L = (1<<10)+9;

int n, m, q;
struct E{
    int x, y, z;
    const bool operator < (const E &cy) const{
        return z < cy.z;
    }
};

vector<E> e[L], nw, g[Q];

long long ans;
long long f[L];

int c[Q], a[Q][N];

struct B{
    int fa[N];
    void init(){
        memset(fa, -1, sizeof(fa));
    }
    int find(int x){
        if(fa[x] < 0) return x;
        return fa[x]=find(fa[x]);
    }
    bool merge(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return 0;
        if(fa[x] < fa[y]) swap(x, y);
        fa[y] += fa[x];
        fa[x] = y;
        return 1;
    }
}b;

int main(){

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ans = 1e18;
    read(n); read(m); read(q);
    e[0].resize(m);
    nw.reserve(m);
    for(int i = 0; i < m; i++){
        read(e[0][i].x); read(e[0][i].y); read(e[0][i].z);
    }
    for(int i = 0; i < q; i++){
        read(c[i]);
        for(int j = 1; j <= n; j++){
            read(a[i][j]);
        }
        for(int j = 1; j <= n; j++){
            g[i].push_back(E{j, n+i+1, a[i][j]});
        }
        sort(g[i].begin(), g[i].end());
    }

    for(int mk = 0; mk < (1<<q); mk++){
        if(mk){
            int lb = (mk&(-mk));
            int p = __lg(mk&(-mk));
            e[mk].resize(e[mk^lb].size()+g[p].size());
            merge(e[mk^lb].begin(), e[mk^lb].end(), g[p].begin(), g[p].end(), e[mk].begin());
        }else{
            sort(e[mk].begin(), e[mk].end());
        }
        b.init();
        nw.clear();
        for(int i = 0; i < e[mk].size(); i++){
            if(b.merge(e[mk][i].x, e[mk][i].y)){
                f[mk] += e[mk][i].z;
                nw.push_back(e[mk][i]);
            }
        }
        swap(nw, e[mk]);
        for(int i = 0; i < q; i++){
            if((mk>>i)&1) f[mk] += c[i];
        }
        ans = min(ans, f[mk]);
    }

    printf("%lld\n", ans);

    return 0;
}