#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int c[100];
void solve()
{
	cin >> s;
	for(int i = 0;i < s.length();++i)
		if(s[i] >= '0' && s[i] <= '9') c[s[i] - '0']++;
	for(int i = 9;i >= 0;--i)
		for(int j = 1;j <= c[i];++j) cout << i;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
}
