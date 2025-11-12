//zhi jing chuan qi O(m + n * (n * k + log n + m)) ni tian kruskal suan fa
#include<bits/stdc++.h>
using namespace std;

const int N = 4e4 + 10, M = 1e6 + 10;
struct node {
	int dis, to;
	long long num;
}arr[M];//cun bian

int fa[N];//fu jie dian
long long n, m, k, cnt = 0, ans = 0;

void add(int u, int v, long long w) {
	cnt++;
	arr[cnt] = (node){u, v, w};
	return ;
}
void made() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	return ;
}
bool cmp(node i, node j) {
	if (i.num == j.num) {
		if (i.dis == j.dis) {
			return i.to < j.to;
		}
		return i.dis < j.dis;
	}
	return i.num < j.num;
}
int find(int x) {
	if (fa[x] == x) {
		return fa[x];
	}
	return fa[x] = find(fa[x]);
}
void kruskal() {
	for (int i = 1; i <= cnt; i++) {
		node now = arr[i];
		int x = fa[now.dis], y = fa[now.to];
		if (find(x) != find(y)) {
			fa[find(y)] = find(x);
			ans += now.num;
		}
	}
	return ;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int ui, vi;
		long long wi;
		cin >> ui >> vi >> wi;
		if (ui > vi) {
			swap(ui, vi);
		}
		add(ui, vi, wi);
//		add(ui, vi, wi);
	}
	vector<int> num(n + 1);//cun xin jian cun de lin shi bian
	for (int i = 1; i <= k; i++) {
		long long tmp;
		cin >> tmp;
		for (int j = 1; j <= n; j++) {
			cin >> num[j];
		}
		for (int j = 1; j <= n; j++) {
			for (int q = j + 1; q <= n; q++) {
				add(j, q, 1ll * num[j] + num[q] + tmp);
			}
		}
	}
	made();
	
	sort(arr + 1, arr + cnt + 1, cmp);
//	for (int i = 1; i <= cnt; i++) {
//		cout << "from " << arr[i].dis << "->" << arr[i].to << " is " << arr[i].num << '\n';
//	}
	kruskal();
	cout << ans << '\n';
	return 0;
}
