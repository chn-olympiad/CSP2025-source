#include <bits/stdc++.h>

using namespace std;
int n,k;
int a[5*100005];
long long ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}	
	for(int l=1;l<=n;l++)
	{
		unsigned long long sum=a[l];
		if(sum==k)
		{
			ans++;
			continue;
		}
		for(int r=l+1;r<=n;r++)
		{
			sum=sum^a[r];
			if(sum==k)
			{
				ans++;
				l=r+1;
				continue;
			}
		} 
	}
	cout<<ans;
	return 0;
}
