#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long n,ans = 0;
int a[5005];

void bfs(long long cnt,int i,int now)
{
	if(i > n) return;
	for(; i <= n; i++)
	{
		if(now >= 2)
		{
			if(cnt + a[i] > 2*a[i])
			{
				ans++;
				bfs(cnt+a[i],i+1,now+1);
			}
			else
			{
				bfs(cnt+a[i],i+1,now+1);
			}
		}
		else
		{
			bfs(cnt+a[i],i+1,now+1);
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	bool teshu = true;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
		if(a[i]!=1) teshu = false;
	}
	sort(a+1,a+n+1);
	
	if(teshu)
	{
		long long ans1 = 0;
		int p = 1;
		int q = n-2;
		while(p<=n-2)
		{
			ans1++;
			p++;
			q--;
		}
		cout << ans1%mod;
		return 0;
	}
	for(int i = 1; i<=n-2; i++)
	{
		bfs(a[i],i+1,1);
	}
	cout << ans%mod;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
