#include <bits/stdc++.h>
using namespace std;
bool b[501];
string s;
int ans = 0, n, m, a[501];
void v(int x, int now)
{
	if(x==n+1)
	{
		if(now>=m)
		{
			ans++;
		} 
		return;
	}
	for(int i = 1; i<=n; i++)
	{
		if(!b[i])
		{
			b[i]=true;
			if(x-now-1>=a[i] || s[x]=='0')
			{
				v(x+1, now);
			}
			else
			{
				v(x+1, now+1);
			}
			b[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s=' '+s;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
	}
	v(1, 0);
	cout << ans << endl;
	return 0;
}
