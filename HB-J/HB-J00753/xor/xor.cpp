#include <iostream>
#define N 500000
using namespace std;
int n,a[N],k,ans;
int dp[N],fa[N];
bool yes[N],h[N];
int work(int l,int r)
{
	int ans=a[l];
	for (int i=l+1;i<=r;i++)
		ans=(ans^a[i]);
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n>> k;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	fa[0]=1;
	for (int i=1;i<=n;i++)
	{
		fa[i]=fa[i-1];
		int t=work(fa[i],i);
		if (t>k)
		{
			dp[i]=1;
			fa[i]=i;
		}
		if (t==k)
		{
			dp[i]=dp[i-1]+1;
			yes[i]=1;
			continue;
		}
		else
		{
			dp[i]=dp[i-1]+1;
		}
		if (a[i]==k)
		{
			ans++;
			h[a[i]]=1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (yes[i])
		{
			if (!h[fa[i]])
			{
				ans++;
				h[fa[i]]=1;
			}
		}
	}
	cout << ans;
	return 0;
}
