#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5010],ans = 0,n;
#define MAXN 998244353
bool check(int sum,int i)
{
	return sum > i;
}

void dfs(int i,int sum){
	if(i > n)return;
	if(check(sum,a[i]))
	{
		//cout << sum << " " << a[i] << endl;
		ans=(ans+1)%MAXN;
		dfs(i+1,sum + a[i]);
		dfs(i+1,sum);
	}
	else
	{
		dfs(i+1,sum+a[i]);
		dfs(i+1,sum);
	}
}

signed main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool flag = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i]!=1)flag = 0;
	}
	if(flag==1)
	{
		int mul = 0;
		for(int i = n;i > 2;i--)
		{
			int tp = 1;
			for(int j = n;j > n-i;j--)
			{
				tp = tp * j;
			}
			for(int j = i;j > 0;j--)
			{
				tp = tp / j;
			}
			mul += tp%MAXN;
			mul %= MAXN;
		}
		cout << mul;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout <<ans;
	return 0;
}
