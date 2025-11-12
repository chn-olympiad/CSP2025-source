#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,k,a[500005],cnt;
bool flag=true,flag2=true;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		flag=false;
		if(a[i]!=1&&a[i]!=0)
		flag2=false;
	}
	if(k==0&&flag)
	{
		cout<<n/2;
		return 0;
	}
	if(flag2&&k<=1)
	{
		if(k==1)
		{
			
		}
	}
	cout<<cnt;
	return 0;
}