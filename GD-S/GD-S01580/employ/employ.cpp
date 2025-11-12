#include <iostream> 
#include <string> 
#include <algorithm>

using namespace std;

const int N = 110;

const int M = 1;

int vis[N];
int vl[N];
int sum[N];
int cnt[N];
int a[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	
	int n, m;
	cin >> n >> m;
	cin >> str;
	
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '1') {
			sum[i+2] = 0;
			cnt[i+1] = cnt[i] + 1;
		} else {
			sum[i+2] = sum[i+1] + 1;
			cnt[i+1] = 0;
		}
	}
	
	int max_p = -1;
	
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		vl[p+1]++;
		max_p = max(max_p, p+1);
	}
	
	for (int i = 1; i <= max_p; i++) {
		vl[i] += vl[i-1];
	}
	
	long long ans = 1;
	
	for (int i = 1; i <= m; i++) {
		ans = ((max(vl[max_p] - vl[sum[i]] - i, 1) % 998244353) * (ans % 998244353)) % 998244353;
	}
	
	cout << ans;
	
	return 0;
} 
