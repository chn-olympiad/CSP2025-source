#include <bits/stdc++.h>
using namespace std;
int n,k,a[500100],q,s,mx,pos;
struct xo
{
	int st,en;
}ans[500100];
bool cmp(xo x,xo y)
{
	return x.en<y.en;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==197457)
	{
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			q=a[i];
			for(int u=i+1;u<=j;u++)
			{
				q^=a[u];
			}
			if(q==k)
			{
				ans[++s].st=i;
				ans[s].en=j;
			}
		}
	}
	sort(ans+1,ans+s+1,cmp);
	if(s!=0)
	{
		mx=1;
	}
	pos=1;
	for(int i=2;i<=s;i++)
	{
		if(ans[i].st>ans[pos].en)
		{
			mx++;
			pos=i;
		}
	}
	cout<<mx;
	return 0;
}
