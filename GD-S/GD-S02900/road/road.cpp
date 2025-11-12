#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define LL long long
typedef pair<int, int> PII;
LL read(){LL x; scanf("%lld", &x); return x; }

const int N = 2e4 + 100;
const int M = 2e6 + 100;
const int K = 22;

int n, m, k;
int ue[M], ve[M], we[M];
int a[K][N], c[K];

struct Edge{int u, v, w; };
vector<Edge> sot[2];
bool cmpe(Edge x, Edge y){return x.w < y.w; }

LL ans;
int pa[N];
int fdp(int x){return pa[x] == x ? x : pa[x] = fdp(pa[x]); }
__inline void merge(int x, int y){x = fdp(x); y = fdp(y); pa[x] = y; }
__inline LL kruskal(int s){
    LL res = 0; int gte = 0, p = n; sot[1].clear();
    for(int i = 1; i <= k; i ++)
        if((s >> (i - 1)) & 1){
            res += c[i]; p ++;
            for(int j = 1; j <= n; j ++)sot[1].push_back({n + i, j, a[i][j]});
        }
    for(int i = 1; i <= n + k; i ++)pa[i] = i;
    
    sort(sot[1].begin(), sot[1].end(), cmpe);
    int t[2] = {0, 0};
    while(t[0] < sot[0].size() || t[1] < sot[1].size()){
        int u, v, w, c;
		if(t[0] == sot[0].size())c = 1;
		else if(t[1] == sot[1].size())c = 0;
		else c = sot[0][t[0]].w > sot[1][t[1]].w;
		u = sot[c][t[c]].u; v = sot[c][t[c]].v; w = sot[c][t[c]].w; t[c] ++;
        if(fdp(u) != fdp(v))merge(u, v), res += w, gte ++;
        if(gte == p - 1)break;
    }
    return res;
}

void solve(int qid){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
    n = read(); m = read(); k = read();
    for(int i = 1; i <= m; i ++)ue[i] = read(), ve[i] = read(), we[i] = read(), ans += we[i];
    for(int i = 1; i <= k; i ++){
        c[i] = read();
        for(int j = 1; j <= n; j ++)a[i][j] = read();
    }

    for(int i = 1; i <= m; i ++)sot[0].push_back({ue[i], ve[i], we[i]});
    sort(sot[0].begin(), sot[0].end(), cmpe);
    for(int s = 0; s < (1 << k); s ++)ans = min(kruskal(s), ans);

    printf("%lld", ans);
}

signed main(){
    int tii = 1;
    for(int z = 1; z <= tii; z ++)solve(z);
    return 0;
}

