#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

string s;
char ans[N];
int cnt;

int main () {

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> s;
	
	int len = s.length();
	
	for (int i = 0;i < len;i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ans[++ cnt] = s[i];
		}
	}
	
	sort (ans + 1,ans + cnt + 1);
	
	for (int i = cnt;i >= 1;i --) {
		cout << ans[i];
	}
	
	return 0;
}

