#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 1;
const int mod = 998244353;
bool s[N];
int n, m, c[N], p[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	for(int i = 1; i <= n; i++)
	{
		p[i] = i;
		cin >> c[i];
	}
	int tot = 0;
	do
	{
		int dc = 0;
		for(int i = 1; i <= n; i++)
		{
			if(dc >= c[p[i]] || !s[i]) dc++;
		}
		if(n - dc >= m) tot = (tot + 1) % mod;
	}while(next_permutation(p + 1, p + n + 1));
	cout << tot;
	return 0;
}

