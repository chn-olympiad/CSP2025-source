#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1e6 + 5,N = 1e4 + 15;

int n,m,k;
struct Node{
    int u,v,w;
    bool operator<(const Node & other) const {
        return w < other.w;
    }
} e[M],et[N * 12];
int cnt;

int f[N],sz[N];
int find(int x){
    if(f[x] != x) return f[x] = find(f[x]);
    return x;
}
int c[N];

void merge(int x,int y){
    x = find(x);y = find(y);
    if(sz[x] < sz[y]) swap(x,y);
    f[y] = x;
    sz[x] += sz[y];
}

long long ans = 9e18;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
    for(int i = 1;i <= m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1,e + m + 1);
    for(int i = 1;i <= m;i++){
        if(find(e[i].u) == find(e[i].v)) continue;
        f[find(e[i].u)] = find(e[i].v);
        et[++cnt] = e[i];
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            int a;
            cin >> a;
            et[++cnt] = {i + n,j,a};
        }
    }

    sort(et + 1,et + cnt + 1);
    for(int S = 0;S < (1 << k);S++){
        long long res = 0;
        for(int i = 1;i <= n;i++){
            f[i] = i;
            sz[i] = 1;
        }
        for(int i = 0;i < k;i++){
            if((S >> i) & 1){
                f[n + i + 1] = n + i + 1;
                sz[n + i + 1] = 1;
                res += c[i + 1];
            }
        }
        for(int i = 1;i <= cnt;i++){
            if(et[i].u > n && !((S >> et[i].u - n - 1) & 1)) continue;
            if(find(et[i].u) == find(et[i].v)) continue;
            // if(S == 1) cerr << res << ' ' << et[i].u << ' ' << et[i].v << ' ' << et[i].w << endl;
            merge(et[i].u,et[i].v);
            res += et[i].w;
        }
        ans = min(ans,res);
    }

    cout << ans << endl;
}