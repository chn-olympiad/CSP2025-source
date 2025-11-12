#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	int n;
	long long k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	for(int i=0;i<n;i++)
	{
		long long sum=0;
		for(int j=i;j<n;j++)
		{
			sum=sum^a[j]; 
		}
		if(sum==k)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
