#include<bits/stdc++.h>
using namespace std;
int a[500005];//50%
int main ()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for (int i=1;i<=n;i++) 
	{
		int s=a[i];
		if (s==k)
		{
			ans++;
		}
		for (int j=i+1;j<=n;j++)
		{
			s=s^a[j];
			if (s==k)
			{
				ans++;
			}	
		}
	}
	cout<<ans;
	return 0;
}
