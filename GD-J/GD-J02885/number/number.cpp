#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
string s;
int cnt[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> s;n = s.size();s = " " + s;
	for (int i = 1;i <= n;i++){
		if ('0' <= s[i] && s[i] <= '9') cnt[(int)(s[i] - '0')]++;
	}for (int i = 9;i >= 0;i--) for (int j = 1;j <= cnt[i];j++) cout << i;
	return 0;
}
