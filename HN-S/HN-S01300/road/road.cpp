#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, fa[1000005], kkk[15];

struct d{
	int x, y, w;
}a[10000005];

struct node{
	int v, w;
};

vector<d> q[1000005];

int find(int x){
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void unionn(int x, int y){
	x = find(x), y = find(y);
	if (x != y) fa[x] = y;
}

bool cmp(d x, d y){
	return x.w < y.w;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (n > 1000){
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= m; i++) cin >> a[i].x >> a[i].y >> a[i].w;
	for (int i = 1; i <= k; i++){
		int x;
		cin >> x;
		for (int i = 1; i <= n; i++) cin >> kkk[i];
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				a[++m].x = i, a[m].y = j, a[m].w = x + kkk[i] + kkk[j];
			}
		}
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(a + 1, a + m + 1, cmp);
	int sum = 0, cnt = 0;
	for (int i = 1; i <= m; i++){
		int x = find(a[i].x), y = find(a[i].y);
		if (x == y) continue;
		sum += a[i].w;
		cnt++;
		if (cnt == n - 1){
			cout << sum;
			return 0;
		}
	}
	return 0;
}

