#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,sum=0;
ll a[500007];
bool v[500007];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			sum++;
			v[i]=1;
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int ans=0;
			ans+=a[i];
			for(int m=i;m<=j;m++)
			{
				if(v[m]==1)
				{
					break;
				}
				ans^=a[m];
			}
			if(ans==k)
			{
				sum++;
				for(int m=i;m<=j;m++)
				{
					v[i]=1;
				}
			}	
		}
	}
	cout<<sum;
	return 0;
}
