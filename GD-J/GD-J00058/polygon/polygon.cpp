#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],s;
int f(int x[],int l,int y)
{
	if(l>=4)
	{
		int ans=0;
		for(int k=1;k<=l-1;k++)
		{
			ans+=a[x[k]];
		}
		if(ans>a[x[l-1]]*2)s++,s=s%998244353;
		
	}
	if(l==y)return 0;
	for(int j=x[l-1]+1;j<=y;j++)
	{
		x[l]=j;
		f(x,l+1,y);
	}
	
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f(b,1,n);
	cout<<s;
	return 0;
}

