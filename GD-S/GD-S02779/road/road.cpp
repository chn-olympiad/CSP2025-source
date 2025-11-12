#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int M = 1000010;
struct xx {
	long long u, v, w;
};
xx e[M];
long long b[N], fa[N];
//vector<xx> E;
long long minn (int A, int B) {
	return A < B ? A : B;
}
int find (int A) {
	if (fa[A] == A) return A;
	return fa[A] = find (fa[A]);
}
bool cmp (xx &A, xx &B) {
	if (A.w == B.w) {
		return A.u < B.u;
	}
	return A.w < B.w;
}
//void workA() {
	
//}
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//bool xzA = true;
	long long n, m ,k;
	cin >> n >> m >> k;
	long long idx = -1;
	for (int i = 0; i < m; i ++) {
		cin >> e[++idx].u >> e[idx].v >> e[idx].w;
	}
	for (int i = 0; i < k; i ++) {
		int c;
		cin >> c;
		//if (c != 0) xzA = false;
		for (int j = 1; j <= n; j ++) {
			cin >> b[j];
			//if (b[j] != 0) xzA = false;
		}
		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k <= n; k ++) {
				if (j == k) continue;
				e[++idx].u = i;
				e[idx].v = j;
				e[idx].w = b[j] + b[k] + c;
			}
		}
	}
	//if (xzA) {
	//	workA ();
	//	return 0; 
	//}
	for (int i = 1; i < n; i ++) {
		fa[i] = i;
	}
	sort (e, e + idx + 1, cmp);
	long long cnt = 0;
	long long sum = 0;
	for (int i = 0; i <= idx; i ++) {
		if (cnt == n - 1) break;
		if (find (e[i].u) != find (e[i].v)) {
			cnt ++;
			sum += e[i].w;
			//cout << sum << endl;
			fa[e[i].u] = find (e[i].v);
		}
	}
	cout << sum;
	return 0;
}
//怎么挂了qwq 
//怎么用数组又可以了
//样例二没过。。 
