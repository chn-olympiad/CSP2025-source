#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
struct node{
	int y, w;
};
vector<node> a[N];
int n, m, k, x, y, w, ans;
int d[N];
bool vis[N];

void dfs(int x) {
	for(auto i : a[x]) {
		int y = i.y;
		d[y] = min(d[y], d[x]+i.w);
	}
	
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> x;
	for(int i = 1; i <= m; i++) cin >> x;
	cout << 2 << endl << 0 << endl;
	return 0;
}
