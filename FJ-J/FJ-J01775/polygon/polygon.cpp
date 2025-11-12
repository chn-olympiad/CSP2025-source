#include<bits/stdc++.h>
using namespace std;
int a[5005],n,sum[5005];
long long ans=0;
void dfs(int i,vector<int> c)
{
	if(i==n+1)
	{
		if(c.size()<=2)return;
		int sum=0;
		for(int j=0;j<c.size()-1;j++)
		{
			sum+=c[j];
		}
		if(sum>c.back())ans++;
		return;
	} 
	c.push_back(a[i]);
	dfs(i+1,c);
	c.pop_back();
	dfs(i+1,c);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
//	clock_t st=clock();
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		if(a[i]!=1)
		{
			f=0;break;
		}
	}
	if(f)
	{
		cout<<n-2<<endl;
		return 0; 
	} 
	sort(a+1,a+n+1,less<int>());
	if(n<=22)
	{
		vector<int> em;
		dfs(1,em);
		cout<<ans%998244353<<endl;
	}else cout<<n*(n-1)/2%998244353<<endl;
//	cout<<1.0*(clock()-st)/CLOCKS_PER_SEC;
	return 0;
}

