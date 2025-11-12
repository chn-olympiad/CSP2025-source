#include <bits/stdc++.h>
using namespace std;

long long c[505], cnt[505], f[505];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int N = 998244353;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		cnt[c[i]]++;
	}
	long long mul = 1;
	for(int i = 1; i <= n; i++)
	{
		if(!f[c[i]])
		{
			while(cnt[c[i]])
			{
				mul *= cnt[c[i]] % N;
				cnt[c[i]]--;
			}
			f[c[i]] = 1;
		}
	}
	long long ans = 0; 
	do
	{
		int x = 0, sum = 0;
		for(int i = 1; i <= n; i++)
		{
			while(c[i] <= x)
			{
				i++;
			}
			if(s[i - 1] == '1')
			{
				sum++;
			}
			else
			{
				x++;	
			}
		}
		if(sum >= m)
		{
			ans = (ans + mul) % N;
		}
	}while(next_permutation(c + 1, c + n + 1));
	cout << ans;
	return 0;
}
