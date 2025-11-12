#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 20;
string s;
int n, cnt[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	n = s.size();
	s = " " + s;
	for(int i = 1;i <= n; ++ i)
	{
		if('0' <= s[i] && s[i] <= '9')
			cnt[s[i] - '0'] ++;
	}
	for(int i = 9;i >= 0; -- i)
		for(int j = 1;j <= cnt[i]; ++ j)
			cout << i;
	return 0;
}
