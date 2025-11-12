#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k;
int pos;
int f[10003];
int c[13];
int a[13][10003];
long long s;
struct edge {
	int u,v,w;
} e[10000003];
bool cmp(edge x,edge y) {
	return x.w < y.w;
}
int find(int x) {
	if (f[x] == x)    return x;
	return f[x] = find(f[x]);
}
void uni(int x,int y) {f[find(x)] = find(y);}
void kk() {
	for (int i = 1; i <= n; i++)    f[i] = i;
	int cnt = 0;
	for (int i = 1; i <= pos; i++) {
		int u = e[i].u,v = e[i].v,w = e[i].w;
		if (find(u) == find(v))    continue;
		uni(u,v);
		s += w;
		cnt++;
		if (cnt == n - 1)    break;
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[++pos] = {u,v,w};
		e[++pos] = {v,u,w};
	}
	sort(e + 1,e + pos + 1,cmp);
	kk();
	bool flag = true;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0)    flag = false;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0)    flag = false;
		}
	}
	if (flag && k > 0)    cout << 0;
	else    cout << s;
	return 0;
}
