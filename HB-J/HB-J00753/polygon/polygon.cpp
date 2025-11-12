#include <iostream>
using namespace std;
int n,a[5005],t[5005],ans,len;
void dfs(int k)
{
	if (k==n+1)
	{
		int maxx=0,sum=0;
		for (int i=1;i<=len;i++)
		{
			sum+=t[i];
			maxx=max(maxx,t[i]);
		}
		if (sum>maxx*2&&len>=3)
		{
			ans++;
			ans=ans%998244353;
		}
		return ;
	}
	for (int i=0;i<=1;i++)
	{
		if (i==0)
		{
			dfs(k+1);
		}
		if (i==1)
		{
			t[++len]=a[k];
			dfs(k+1);
			len--;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}
