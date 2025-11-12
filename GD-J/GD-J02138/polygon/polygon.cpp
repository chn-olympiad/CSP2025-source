#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int add[5005];
int ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxl=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add[i]=a[i]+add[i-1];//
		maxl=max(maxl,a[i]);
	}
	if(n==3&&add[n]>2*maxl)
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		//a[i]×÷ÎªmaxlÊ±
		for(int j=i+1;j>=2;j--)
		{
			for(int k=j+1;k>=1;k--)
			{
				int sum=add[i]-add[k-1]-(add[i-1]-add[j]);
				if(sum>2*a[i])ans=(ans+1)%998244353;
			}
		} 
	}
	cout<<ans;
	return 0;
}
