#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[509], a[509];
bool b[509];
long long cnt;
void dfs(int k, int r, int x, int k2)
{
	if(k == n)
	{
		//cout << "±¾ÂÖ:Â¼È¡" << r << " ÌÔÌ­" << x << endl; 
		if(r >= m) cnt = (cnt+1)%998244353;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(b[i] == 0)
		{
			if(x>=a[i])
			{
				b[i] = 1;
				//cout << "dfs(" << k+1 << ", " << r << ", " << x+1 << ") ÌÔÌ­:" << i << endl;
				dfs(k+1, r, x+1, k2+1);
				b[i] = 0;
			}
			else if(s[k2] == 0)
			{
				b[i] = 1;
				//cout << "dfs(" << k+1 << ", " << r << ", " << x+1 << ") ÌÔÌ­:" << i << endl;
				dfs(k+1, r, x+1, k2+1);
				b[i] = 0;
			}
			else if(s[k2] == 1)
			{
				b[i] = 1;
				//cout << "dfs(" << k+1 << ", " << r+1 << ", " << x << ") Ñ¡Ôñ:" << i << "\n";
				dfs(k+1, r+1, x, k2+1);
				b[i] = 0;
			}
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	bool flag = 1;
	for(int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		s[i] = c-'0';
		if(s[i]==0) flag = 0;
	}
	int k = n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 0) k--;
	}
	if(flag)
	{
		if(k < m)
		{
			cout << 0;
			return 0;
		}
		//cout << k << " ";
		cnt = 1;
		for(int i = 1; i <= k; i++)
		{
			cnt = (cnt*i)%998244353;
		}
		cout << cnt;
		return 0;
	}
	dfs(0, 0, 0, 1);
	cout << cnt;
	return 0;
}

