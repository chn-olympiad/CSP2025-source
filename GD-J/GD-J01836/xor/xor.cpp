#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l,r=n;
	bool check=0;
	for(l=1;l<=n;l++)
	{
		if(l==r&&check)
		{
			r=n;
			ans++;
			check=0;
			continue;
		}
		if(a[l]==k)
		{
			r=n;
			ans++;
			check=0;
			continue;
		}
		int temp=a[l];
		for(int j=l+1;j<=r;j++)
		{
			temp=(temp xor a[j]);
			if(temp==k)
			{
				r=j;
				check=1;
			}
		}
	}
	cout<<ans;
	return 0; 
}
