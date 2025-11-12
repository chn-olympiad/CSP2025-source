#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;
int a[N], pre[N];
int n, k;
map<int, int> mp;

int main() {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i-1] ^ a[i];
		mp[pre[i]] = 0;
	}
	
	int last = 0, cnt = 0;
	mp[0] = 0;
	
	if(k == 0) {
		for(int i = 1; i <= n; i++) {
			if(pre[i] == 0 && last == 0) {
				cnt += 1;
				last = i;
			} else if(mp[pre[i]] && mp[pre[i]] >= last) {
				cnt += 1;
				last = i;
			}
			mp[pre[i]] = i;
		}
		
		cout << cnt;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		mp[pre[i]] = i;
		int num = k ^ pre[i];
		if(num == 0 && mp[0] == 0 && last <= mp[0]) {
			cnt += 1;
			last = i;
		} else if(mp[num] && mp[num] >= last) {
			cnt += 1;
			last = i;
		}
	}
	
	cout << cnt;
	
	return 0;
}
