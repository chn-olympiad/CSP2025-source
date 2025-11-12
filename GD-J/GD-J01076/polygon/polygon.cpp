#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int p[5000+15];
	int flag = 1;
	int maxn = 0;
	for (int i = 1;i <= n;i++) 
	{cin >> p[i];maxn = max(maxn,p[i]);if (p[i] != 1) flag = 0;}
	unsigned long long ans = 1;
	if (flag == 1)
	{
		for (int i = 3;i <= n;i++)
		{
			unsigned long long o = 1;
			for (int j = i;j <= n;j++)
			{
				o *= (o-1);
				o--;
			}
			ans += o;
		}
		cout << ans << endl;
	}
	else if (n == 3)
	{
		if (p[1] + p[2] + p[3] > 2 * maxn) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
 } 
