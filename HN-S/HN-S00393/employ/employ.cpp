#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[505];
int c[505];
int ind[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	string str;
	cin >> str;
	for(int i = 0;i < n;i++) s[i + 1] = str[i] - '0';
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n;i++) ind[i] = i;
	int ans = 0;
	do {
		int ac = 0,rf = 0;
		for(int i = 1;i <= n;i++) {
			if(rf >= c[ind[i]]) {
				++rf;
				continue;
			}
			if(s[i]) ++ac;
			else ++rf;
			if(ac >= m) break;
		}
		if(ac >= m)
			++ans;
	} while(next_permutation(ind + 1,ind + 1 + n));
	cout << ans;
	return 0; 
} 
