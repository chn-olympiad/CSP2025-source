#include<bits/stdc++.h>
using namespace std;
long long t,n,x,y,z,maxn,a[100005],b[100005],c[100005];
void dfs(long long step,long long x,long long y,long long z,long long sum,long long n)
{
	if (step > n)
	{
		if (x <= n / 2 && y <= n / 2 && z <= n / 2) maxn = max(maxn,sum);
		return;
	}
	dfs(step + 1,x + 1,y,z,sum + a[step],n);
	dfs(step + 1,x,y + 1,z,sum + b[step],n);
	dfs(step + 1,x,y,z + 1,sum + c[step],n);
}
bool cmp(long long x,long long y)
{
	return x > y;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t --)
	{
		maxn = 0;
		long long flag = 1;
		cin>>n;
		for (long long i = 1;i<=n;i++)
		{ 
			cin>>a[i]>>b[i]>>c[i];
			if (b[i] || c[i]) flag = 0;
		}
		if (n <= 12)
		{
			dfs(1,0,0,0,0,n);
			cout<<maxn<<endl;
		}
		else if (flag)
		{
			sort(a+1,a+n+1,cmp);
			for (long long i = 1;i<=n/2;i++) maxn += a[i];
			cout<<maxn<<endl;
		}
		else cout<<n<<endl;
	}
	return 0;	
} 
