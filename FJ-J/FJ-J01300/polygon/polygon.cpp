#include <bits/stdc++.h>
using namespace std;
 
long long n,a[10000],ans[10000],c;

void dfs(long long step)
{
	if(step > n)
	{
		long long addd = 0,maxn = -1,cnt = 0;
		for(long long i = 1;i <= step;i++)
		{
			addd += ans[i];
			if(ans[i]!=0)cnt++;
			maxn = max(maxn,ans[i]);
		}
		if(cnt >= 3&& addd > 2*maxn)c++;
		c %= 998244353;
		return;
	}
	
	ans[step] = a[step];
	dfs(step+1);
	ans[step] = 0;
	dfs(step+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    bool flag = 1;
    for(long long i = 1;i <= n;i++)
    {
    	cin >> a[i];
    	if(a[i] != 1)flag = 0;
	}
	if(flag == 0||n <= 500)
	{
		sort(a+1,a+n+1);
		dfs(1);
		cout << c % 998244353;
	}
	else
	{
		long long u = 0;
		while(n >= 3)
		{
			for(long long i = 1;i <= n-2;i++)
			{
				u += i*(n-1-i);
				u %= 998244353;
			}
			n--;
		}
		cout << u % 998244353;
	}
	return 0;
}
