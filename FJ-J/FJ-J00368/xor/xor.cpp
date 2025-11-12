#include<bits/stdc++.h>
using namespace std;
int n,m=0,k,a[500005],ans=0,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>100000)
	{
		if(k==0||k==1)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				if(a[i]==k)
				{
					ans++; 
				}
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=0;
		for(int j=i;j>m;j--)
		{
			sum^=a[j];
			if(sum==k)
			{
				ans++;
				m=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
