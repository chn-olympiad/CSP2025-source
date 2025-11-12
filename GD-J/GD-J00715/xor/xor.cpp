#include <bits/stdc++.h>
using namespace std;
//string s;
constexpr int N = 5e5 + 5;
//priority_queue<char> q;
//int a[15];
int n,k,a[N],s[N];
bool vis[N];

struct node {
	int d;
	int l,r;
};

/*
int dfs(int l, int r) {
	if (l == r) {
		return a[l] == k ? 1 : 0;
	}
	int mid = (l + r - 1) >> 1;
	int cnt = dfs(l,mid) + dfs(mid + 1, r);
	for(int i = l; i < mid; i++) {
		for(int j = mid; j < r; j++) {
			if (s[j] ^ s[i] == k) {
				cnt = max(cnt,1 + dfs(l,i) + dfs(j, r-1));
			}
		}
	}
	return cnt;
}
*/

int p(int l, int r) {
	int ans = 0,cnt = 0;
	bool flag = 0;
	for(int t = 2; t <= r - l + 1; t++) {
		flag = 0;
		for(int i = l; i <= r + 1 - t; i++) {
			if (vis[i] || vis[i + t - 1]) {
				flag = 1;
				cnt = 0;
				continue;
			}
			if (flag) {
				cnt ++;
				if (cnt == t - 1) flag = 0;
				continue;
			}
			if (s[i - 1] ^ s[i + t - 1] == k) {
				ans ++;
				bool g = 0;
				for(int j = i; j <= i + t - 1; j++) {
					if (!vis[j]) vis[j] = 1;
					else g = 1;
				}
				if (g) ans --;
			}
		}
	}
	return ans;
}

node dfs(int l, int r) {
	if (l == r) {
		return a[l] == k ? node{1,l,l} : node{0,l + 1,l - 1};
	}
	int mid = (l + r - 1) >> 1;
	node cntl = dfs(l,mid);
	node cntr = dfs(mid + 1, r);
	int cnt = cntl.d + cntr.d + p(cntl.r + 1,cntr.l - 1);
	/*
	for(int j = 1; j <= cntr.l - cntl.r; j++) {
		for(int i = cntl.r + j; i <= cntr.l; i++) {
			
		}
	}
	*/
	return node{cnt,cntl.l,cntr.r};
}
int ans = 0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	ans = dfs(1,n).d;
	cout << ans;
//	cout << p(1,n) + ans;
}
