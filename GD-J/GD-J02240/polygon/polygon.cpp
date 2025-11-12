#include<bits/stdc++.h> 
using namespace std;
int n, a[5005], jsq, b;
bool pd;
void dfs(int ad, int ma, int gz, int bs)
{
	if (gz>n+1)
	{
		return ;
	}
	if (bs==b-1)
	{
		for (int i=gz; i<=n; i++)
		{
			if (a[i]>=ad)
			{
				jsq=(jsq+i-gz)%998244353;
				return ;
			}
		}
		jsq=(jsq+n+1-gz)%998244353;
	}
	for (int i=gz; i<=n-b+gz; i++)
	{
		if (pd)
		{
			continue;
		}
		dfs(ad+a[i], max(ma, a[i]), i+1, bs+1);
	}
	pd=false;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for (int i=3; i<=n; i++)
	{
		b=i;
		dfs(0, 0, 1, 0);
	}
	cout << jsq;
	return 0;
}
