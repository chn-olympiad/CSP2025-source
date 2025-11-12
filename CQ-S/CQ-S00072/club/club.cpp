#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int mian(); int main() { return mian(); }

#define ll long long
const int N = 1e5 + 15;
int n, a[N][3], _;

vector<int> p[3];
int val[N];
ll sum;
void maintain(const int j) {
	for(int i = 1; i <= n; ++i) {
		val[i] = 0;
		for(int t = 0; t < 3; ++t) if(t != j) val[i] = max(val[i], a[i][t]);
		val[i] = a[i][j] - val[i];
	}
	sort(p[j].begin(), p[j].end(), [](const int A, const int B) { return val[A] > val[B]; });
	while((int)p[j].size() > n / 2) {
		int i = p[j].back(); p[j].pop_back();
		sum -= val[i];
	}
}
void solve() {
	_ = scanf("%d", &n);
	p[0].clear(); p[1].clear(); p[2].clear();
	sum = 0;
	for(int i = 1; i <= n; ++i) {
		_ = scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		int mac = max({a[i][0], a[i][1], a[i][2]});
		sum += mac;
		if(a[i][0] == mac) p[0].push_back(i);
		else if(a[i][1] == mac) p[1].push_back(i);
		else p[2].push_back(i);
	}
	for(int i = 0; i < 3; ++i) {
		if( (int)p[i].size() > (n / 2) )
			maintain(i);
	}
	printf("%lld\n", sum);
}
int mian() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; _ = scanf("%d", &T);
	while(T--) solve();
	return 0;
}