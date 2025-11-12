#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,z=0;
	cin>>n>>k;
	int a[n+2];
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x==k)
		{
			ans+=1;
			a[z]=-1;
			z++;
		}
		else
		{
			a[z]=x;
			z++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==-1)
		{
			continue;
		}
		int c=a[i];
		for(int j=i+1;a[j]!=-1&&j<n;j++)
		{
			c^=a[j];
			if(c==k)
			{
				ans+=1;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
