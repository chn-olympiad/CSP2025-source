#include<bits/stdc++.h>
using namespace std;	
int n,a[5010],ans=0;
void dfs(int num,int po,int mmax,int sum)//num第几个数，po下标 
{
	if(num>=3)
	{
		if(sum>2*mmax)
		{
			ans=ans%998244353;
			ans++;
		}
		return ;
	}
	for(int i=po;i<n;i++)
	{
		dfs(num+1,i+1,max(mmax,a[i]),sum+=a[i]);
	}
	return ;
}
int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
