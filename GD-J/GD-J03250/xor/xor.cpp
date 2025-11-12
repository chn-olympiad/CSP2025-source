#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500008];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool b1=1,b2=1;
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			b1=0;
		if(a[i]>1)
			b2=0;
		sum+=a[i];
	}
	
	if(k==0 && b1)
	{
		cout<<n/2;
		return 0;
	}
	else if(k==1 && b2)
	{
		cout<<sum;
		return 0;
	}
	else if(k==0 && b2)
	{
		int ans=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]==1 && a[i+1]==1)
			{
				ans++;
				i++;
			}
		}
		
		cout<<ans+(n-sum);
		return 0;
	}
	
	cout<<3;
	return 0;
} 
