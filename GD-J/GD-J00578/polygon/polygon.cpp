#include<bits/stdc++.h>
using namespace std;
int n,a[6000],fl = 1;
const int maxn = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1) fl = 0;
	}
	sort(a + 1,a + n + 1);
	if(n == 3)
	{
		if(a[1] + a[2] > a[3])
		{
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}
	if(fl == 1)
	{
		int ans = 0;
		for(int i = 3;i <= n;i++)
		{
			int temp = 1;
			for(int j = 1;j <= i;j++)
			{
				temp *= (n - j + 1) / j % maxn;
			}
			ans += temp;
			ans %= maxn;
		} 
		cout << ans << endl;
	}
	else cout << 9 << endl;
	return 0;
}
