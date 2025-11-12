#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s=3;
long long ans=0;
void dfs(int h,int j,int cmp)
{
	if(cmp==s)
	{
		if(h>2*a[j])
			ans=(ans+1)% 998244353;
		return;
	}
	for(int i=j+1;i<=n;i++)
		dfs(h+a[i],i,cmp+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3)
	{
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(a[n]<=1)
	{
		for(int i=3;i<=n;i++)
			ans=(ans+n-i+1)%998244353;
		cout<<ans;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		s=i;
		for(int j=1;j<=n;j++)
			dfs(a[j],j,1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 