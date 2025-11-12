#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,zong;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>1) return 0;
	}
	if(k==1)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==1) zong++;
		}
	}
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==0) zong++;
			if(a[i]==1&&a[i+1]==1)
			{
				zong++;
				i++;
			}
		}
	}
	cout<<zong;
	return 0;
}
