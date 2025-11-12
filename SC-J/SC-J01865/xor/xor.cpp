#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 7;

int n, k;
int a[maxn];
int s[maxn];
map<int, int> mp;
int cnt = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int op = 0;
	mp[0] = 1;
	for(int i = 1; i <= n; i ++) {
		s[i] = s[i - 1] ^ a[i];
		if(mp[s[i] ^ k]) {
			cnt ++, s[i] = 0;
			mp.clear();
		}
		mp[s[i]] = 1;
	}
	cout << cnt;
	return 0;	
} 
/*
4 3
2 1 0 3

4 0
2 1 0 3

4 2
2 1 0 3

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
