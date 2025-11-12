#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 2;
string s;
char ans[maxn];
int cnt;
bool cmp(char x, char y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++)
		if('0' <= s[i] && s[i] <= '9')
			ans[++cnt] = s[i];
	sort(ans + 1, ans + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i++)
		cout << ans[i];
	return 0;
}
