#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, ans, c[N], p[N];
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		p[i] = i;
	}
	do
	{
		int sum = 0, tot = 0;
		for(int i = 1;i <= n;i++)
		{
			if(sum >= c[p[i]] || s[i - 1] == '0')
			{
				sum++;
				continue;
			}
			tot++;
		}
		if(tot >= m)
			ans++;
	}while(next_permutation(p + 1, p + n + 1));
	cout << ans << "\n";
	return 0;
}
