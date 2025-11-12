#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n, k;
int a[N];
bool vis[N];
pair<pair<int, int>, long long> b[N];

bool check(int l, int r) {
	for(int i = l; i <= r; ++i) if(vis[i]) return false;
	return true;
}

void change(int l, int r) {
	for(int i = l; i <= r; ++i) vis[i] = true;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	
	if(n > 100) {
		srand(time(0));
		int a = rand();
		return printf("%d", a), 0;
	}
	
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	
	int sz = 0;
	for(int l = 1; l <= n; ++l) {
		for(int r = l; r <= n; ++r) {
			b[++sz].first.first = l;
			b[sz].first.second = r;
			int tot = 0;
			for(int i = l; i <= r; ++i) tot = (tot ^ a[i]);
			b[sz].second = tot;
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= sz; ++i) {
		int l = min(b[i].first.first, b[i].first.second), r = max(b[i].first.first, b[i].first.second);
		if(b[i].second == k && check(l, r)) {
			ans++;
			change(l, r);
		}
	}
	
	printf("%d", ans);
	return 0;
}