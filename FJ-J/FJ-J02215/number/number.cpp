#include <bits/stdc++.h>
using namespace std;
string s;
bool flag = false;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	vector<int> cnt(10, 0);
	for(int i = 0; i < s.size(); ++ i)
		if(s[i] >= '0' && s[i] <= '9')
			++ cnt[s[i] - '0'];
	//for(int i = 0; i <= 9; ++ i) cout << cnt[i] << ' ';
	for(int i = 9; i >= 0; -- i)
		for(int j = 1; j <= cnt[i]; ++ j) {
			if(i > 0 || flag) putchar(i + '0'), flag = true;
			else {
				putchar('0');
				break;
			}
		}
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
