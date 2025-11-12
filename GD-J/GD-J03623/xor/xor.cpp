#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
void solve()
{
	cout << n/2;
	return; 
}
void solve1()
{
	if(k == 0)
	{
		int ans = 0;
		int shu = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == 0)
			{
				ans++;
			} 
			else if(a[i] == 1 && a[i+1] == 1)
			{
				ans++;
				i++;
			}
		}
		cout << ans;
		return;
	}
	else
	{
		int y = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == 0)
			{
				y++;
			}
		}
		cout << y;
		return;
	}
}
int main()
{
	freopen("xor.in","in",stdin);
	freopen("xor.out","out",stdout);
	cin >> n >> k;
	bool ok = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] == 0)
		{
			ok = 1;
		}
	}
	if(k == 0 && ok == 0)
	{
		solve(); 
	}
	else if(ok == 1)
	{
		solve1();
	}
	return 0;
}
