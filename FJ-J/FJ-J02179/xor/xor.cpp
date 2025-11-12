#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool l =1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			l=0;
	}
	if(l==1&&k==0) 
		cout<<n/2;
	else if(k==0)
	{
		int sum=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]==0)
				sum++;
			else if(a[i]==a[i+1])
			{
				sum++;
				i++;                              
			}
		}
		if(a[n]==0)
			sum++; 
		cout<<sum;
	}
	else if(k==1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				sum++;
		}
		cout<<sum;
	}
	return 0;
}
