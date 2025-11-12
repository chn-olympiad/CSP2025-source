#include<bits/stdc++.h>
using namespace std;
struct node{
	int x, y, z;
};
queue<node> a, b, c;
int n, m, ans;
int Ma(int i, int j) {
	return (i > j ? i : j);
}
int Mi(int i, int j) {
	return (i < j ? i : j);
}
bool cmp(node i, node j) {
	return i.x - Ma(i.y, i.z) < j.x - Ma(j.y, j.z);
}
void check(queue<node> &q, queue<node> &r, queue<node> &s) {
	if (q.size() <= m) return;
	vector<node> v;
	for (int i = 1; i <= q.size();) v.push_back(q.front()), q.pop();
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size() - m; ++i) {
		if (v[i].y > v[i].z) r.push({v[i].y, v[i].z, -1});
		else s.push({v[i].z, v[i].y, -1});
	}
	for (int i = v.size() - m; i < v.size(); ++i) q.push(v[i]);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	do{
		cin >> n;
		m = (n >> 1), ans = 0;
		for (int i = 1; i <= n; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			if (u >= v && u >= w) a.push({u, v, w});
			else if (v >= u && v >= w) b.push({v, u, w});
			else if (w >= u && w >= v) c.push({w, u, v});
		}
		check(a, b, c);
		check(b, c, a);
		check(c, a, b);
		for (int i = 1; i <= a.size();) ans += a.front().x, a.pop();
		for (int i = 1; i <= b.size();) ans += b.front().x, b.pop();
		for (int i = 1; i <= c.size();) ans += c.front().x, c.pop();
		cout << ans << endl;
	} while(--t);
	return 0;
}

