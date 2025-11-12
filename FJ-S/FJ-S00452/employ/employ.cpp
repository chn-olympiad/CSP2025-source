#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int mod = 998244353;

int n, m;
string s;
int c[505];

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s; s = " " + s;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	if(n <= 18)
	{
		sort(c + 1, c + n + 1); int ans = 0;
		do
		{
			int tmp = 0;
			for(int i = 1; i <= n; i++)
			{
				if(c[i] == 0) tmp++;
				if(s[i] == '0') tmp++;
				if(c[i] < tmp) tmp++;
			}
			if(n - tmp >= m)
			{
				ans = (ans + 1) % mod;
				for(int i = 1; i <= n; i++)
					cout << c[i] << " ";
				cout << endl;
			}
		}while(next_permutation(c + 1, c + n + 1));
		cout << ans << endl;
	}
	bool flag = true;
	for(int i = 1; i <= s.size(); i++)
		if(s[i] == '0') flag = false;
	if(flag)
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(c[i]) cnt++;
		int ans = 1;
		for(int i = 1; i <= cnt; i++)
			ans = (ans * i) % mod;
		cout << ans << endl;
	}
	return 0;
}
