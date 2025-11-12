#include<bits/stdc++.h>
using namespace std;
struct node {
	int fir, sec;
};
vector<node> v[1000006];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int u, w, l;
	for (int i=1;i<=m;i++) {
		scanf("%d%d%d", &u, &w, &l);
		v[u].push_back(node{w, l});
		v[w].push_back(node{u, l});
	}
	for (int i=1;i<=n;i++) {
		
	}
	return 0;
}
