#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10;
pair<int, int> e[maxn];
 
long long a[maxn], s[maxn], tot=0;
int ans[maxn], r[maxn];
int n, k;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if((s[j] ^ s[i-1]) == k) {
				e[++tot] = {i, j};
			}
		}
	}
	sort(e+1, e+tot+1);
	int tt = 1;
	r[1] = -1;
	for(int i=1; i<=tot; i++) {
		int el = e[i].first;
		int er = e[i].second;
//		cout << el << " " << er << "\n"; 
		bool flag = 0;
		for(int j=1; j<=tt; j++) {
			if(r[j] < el) {
				++ans[j];
				r[j] = er;
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			r[++tt] = er;
			++ans[tt];
		} 
	}
	int cnt = 0;
	for(int i=1; i<=tt; i++) {
		cnt = max(cnt, ans[i]);
	}
	cout << cnt;
	return 0;
}
/*
4 0
2 1 0 3
*/
