#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
int n, m, k;
int res;
struct Edge{
    int u, v, w;
}e[N];
int idx;
int pd[N];
bool cmp(Edge x,Edge y) {
    return x.w < y.w;
}
int find(int &x) {
    if(x == pd[x])return x;
    return find(x = pd[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[++idx].u = x;
        e[idx].v = y;
        e[idx].w = z;
    }
    for(int i = 1;i <= k;i++) {
        int c;
        cin >> c;
        for(int j = 1;j <= n;j++) {
            int x;
            cin >> x;
            e[++idx].u = n + i;
            e[idx].v = j;
            e[idx].w = x;
        }
    }
    sort(e + 1,e + idx + 1,cmp);
    for(int i = 1;i <= n;i++)pd[i] = i;
    for(int i = 1;i <= n;i++) {
		int u = e[i].u;
		int v = e[i].v;
		int w = e[i].w;
		if(find(u) != find(v)) {
			pd[v] = u;
			res += w;
		}
	}
    cout << res << '\n';
    return 0;
}
