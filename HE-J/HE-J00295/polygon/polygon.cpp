#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]+b[i-1];
		c[i]=max(a[i],a[i-1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(j!=i+1)
			{
				if(b[j]+a[i]<2*c[j])
				{
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
