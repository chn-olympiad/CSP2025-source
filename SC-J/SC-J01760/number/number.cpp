#include<bits/stdc++.h>
#define ll long long
#define ls p * 2
#define rs p * 2 + 1
#define mid ((l + r) / 2)
#define lson ls, l, mid
#define rson rs, mid + 1, r
using namespace std;
const int N = 1e6 + 10;
string s;
int ans[N], cnt;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	s = ' ' + s;
	for(int i = 1;i <= s.length();i++) {
		if(s[i] <= '9' and s[i] >= '0') {
			ans[++cnt] = s[i] - '0';
		}
	}
	sort(ans + 1, ans + cnt + 1, cmp);
	for(int i = 1;i <= cnt;i++) cout << ans[i];
	return 0;
}