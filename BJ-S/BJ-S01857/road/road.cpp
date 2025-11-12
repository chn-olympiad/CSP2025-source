#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 5;
const int M = 1e5 + 5;
const int K = 10 + 5;
struct Edge {
    int u , v , w;
} e[M];
int n , m , k , pn , pm , pk , a[K][N] , c[K];
bool A = 1;
int Read() {
    int num = 0;
    char ch;
    while(ch = getchar()) {
        if(isdigit(ch)) num = num * 10 + (ch - '0');
        else break;
    }
    // cout << "num: " << num << endl;
    return num;
}
namespace Work1 {
    int f[N];
    int Find(int x) {
        if(f[x] == x) return x;
        int fx = Find(f[x]);
        f[x] = fx;
        return fx;
    }
    void Union(int x , int y) {
        f[Find(x)] = f[Find(y)];
    }
    bool cmp(Edge x , Edge y) { return x.w < y.w; }
    void Solve() {
        sort(e + 1 , e + m + 1 , cmp);
        for(int i = 1;i <= n;i++) f[i] = i;
        int ans = 0;
        for(int i = 1;i <= m;i++) {
            int u = e[i].u , v = e[i].v , w = e[i].w;
            if(Find(u) != Find(v)) {
                Union(u , v);
                ans += w;
            }
        }
        cout << ans << endl;
    }
}
namespace WorkA {
    int f[N];
    int Find(int x) {
        if(f[x] == x) return x;
        int fx = Find(f[x]);
        f[x] = fx;
        return fx;
    }
    void Union(int x , int y) {
        f[Find(x)] = f[Find(y)];
    }
    bool cmp(Edge x , Edge y) { return x.w < y.w; }
    void Solve() {
        cout << "In A" << endl;
        for(int i = 1;i <= k;i++) {
            for(int j = 1;j <= n;j++) {
                e[++m] = Edge{i , j , a[i][j]};
            }
        }
        sort(e + 1 , e + m + 1 , cmp);
        cout << "After sort" << endl;
        for(int i = 1;i <= n;i++) f[i] = i;
        int ans = 0;
        for(int i = 1;i <= m;i++) {
            cout << i << endl;
            int u = e[i].u , v = e[i].v , w = e[i].w;
            if(Find(u) != Find(v)) {
                Union(u , v);
                ans += w;
            }
        }
        cout << ans << endl;
    }
}
int main() {
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    // ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u , v , w;
        cin >> u >> v >> w;
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
        // cout << m << endl;
    }
    // cout << n << " " << m << " " << k << endl;
    // cout << pn << " " << pm << " " << pk << endl;
    for(int i = 1;i <= k;i++) {
        cin >> c[i];
        // cout << c[i] << endl;
        if(c[i] != 0)  {
            A = 0;
        }
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    if(k == 0) { Work1::Solve(); return 0; }
    if(A) { WorkA::Solve(); return 0; }
    return 0;
}