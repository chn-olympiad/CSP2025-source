#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
		}
	}
	else
	{
		sum+=n;
		for (int i=1;i<=n;i++)
		{
			sum-=a[i];
		} 
	}
	cout<<sum;
	return 0;
} 
