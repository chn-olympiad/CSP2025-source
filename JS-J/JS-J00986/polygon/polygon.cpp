#include <iostream>
#include <vector>
using namespace std;
#define N 5005

int n, ans;
int a[N];

vector<int> b;
bool vis[N];
//choose x+1th thing
void dfs(int x) {
	if (x == n) {
		b.clear();
		for (int i=1; i<=n; i++) {
			if (vis[i]) b.push_back(a[i]);
		}
		int sum = 0, maxl = 0;
		for (int i=0; i<b.size(); i++) {
			sum+=b[i];
			maxl = max(maxl, b[i]);
		}
		if (sum > maxl*2) {
			ans = (ans+1) % 998244353;
		}
		return;
	}
	//nochoose x+1
	vis[x+1] = 0;
	dfs(x+1);
	//choose x+1
	vis[x+1] = 1;
	dfs(x+1);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	dfs(0);
	cout << ans;
	return 0;
}
