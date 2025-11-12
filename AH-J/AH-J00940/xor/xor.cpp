#include<bits/stdc++.h>
using namespace std;
int a[500005]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(k==0)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else if(a[i]==a[i+1])
			{
				ans++;
				i++;
			}
		}
		if(k==1)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
