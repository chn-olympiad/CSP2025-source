#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	long long ans=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		long long sum=a[i];
		if(sum==k)
		{
			ans++;	
			continue;
		}
		for(int j=i+1;j<n;j++)
		{
			sum^=a[j];		
			if(sum==k)
			{
				ans++;
				i=j;
				j=n+1;
			}
		}
	}
	cout<<ans;
	return 0; 
}
