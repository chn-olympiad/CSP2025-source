#include<bits/stdc++.h>
using namespace std;
int dg(int n,vector<int> a,int m,int nums)
{
	if(m>n)
	{
		return nums%998244353;
	}
	for(int i=0;i<n-m;i++)
	{
		int x,nu,ma=a[i];
		for(int j=0;j<m;j++)
		{
			nu=i+j;
			ma=max(ma,a[nu]);
			x=x+a[nu];
		}
		if(x>=ma+ma)
		{
			nums++;
		}
	}
	return dg(n,a,m,nums);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int x=dg(n,a,3,0);
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
