#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[N];
	int juq1=0,juq0=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) juq1++;
		if(a[i]==0) juq0++;
	}
	if(k==0&&juq1==n)
	{
		cout<<n/2;
		return 0;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1&&a[i+1]==1)
			{
				juq0++;
				a[i+1]=0;
			}
		} 
		cout<<juq0;
		return 0;
	}
	if(k==1)
	{
		cout<<juq1;
		return 0;
	}
	return 0;
}
