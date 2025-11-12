#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, k, a[N], s[N], ans;
map<int, int> now;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
		if ((now.find(s[i] ^ k) != now.end()) || (s[i] ^ k) == 0){
			++ans;
			now.clear();
			s[i] = 0;
		}
		else{
			now[s[i]] = 1;
		}
	}
	cout << ans;
	return 0;
}
