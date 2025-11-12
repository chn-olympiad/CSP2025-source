#include <iostream>
#include <algorithm>
using namespace std;
int ans,m = 998244353,a[5005],s[5005];
bool v[5005];
void c(int n)
{
	int p = 1;
	for(int i = 1;i <= n;i++)
		p = (p * 2) % m;
	cout << (p + m - 1 - n - (n - 1) * n / 2) % m << endl;
}
void dfs(int st,int n,int sum)
{
	if(st >= n)
	{
		if(sum > a[n])
		{
			ans = (ans + 1) % m;
		}
		return;
	}
	for(int i = 1;i < n;i++)
	{
		if(!v[i])
		{
			v[i] = 1;
			dfs(st + 1,n,sum + a[i]);
			v[i] = 0;
			dfs(st + 1,n,sum);
			
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1,a + n + 1);
	if(n <= 3)
		cout << (a[1] + a[2] > a[3]) << endl;
	else if(a[n] == 1)
	{
		c(n);
	}
	else
	{
		for(int i = 3;i <= n;i++)
		{
			if(s[i - 1] <= a[n]) continue;
			dfs(2,i,0);
		}
		cout << ans << endl;
	}
	return 0;
}
