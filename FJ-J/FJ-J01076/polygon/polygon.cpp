#include<bits/stdc++.h>
using namespace std;
long long n,l[5010],ans=0;
void dfs(int sum,long long mx,int num,int x,bool sf)
{
	if (num>=3&&sum>mx*2&&sf)
		ans=(ans+1)%998244353;
	if (x==n)
		return;
	dfs(sum+l[x],max(mx,l[x]),num+1,x+1,true);
	dfs(sum,mx,num,x+1,false);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int mx=0;
	for (int i=0;i<n;i++)
	{
		cin >> l[i];
		if (l[i]>mx)
			mx=l[i];
	}
	if (mx==1)
	{
		long long sum=n*(n-1)*(n-2);
		for (int i=4;i<=n;i++)
		{
			if ((n-i+1)%i==0)
			{
				sum*=(n-i+1)/i;
				ans+=sum;
				ans%=998244353;
				sum%=998244353;
			}
			else
			{
				sum/=i;
				sum*=(n-i+1);
				ans+=sum;
				ans%=998244353;
				sum%=998244353;
			}
		}
		cout << ans;
		return 0;
	}
	dfs(0,0,0,0,false);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
