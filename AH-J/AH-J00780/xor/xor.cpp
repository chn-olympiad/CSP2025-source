#include<bits/stdc++.h>
using namespace std;
long long a[10005];
long long f[10005][10005]={0};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long i,j,n,m,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			f[i][j]=f[i][j-1]^a[j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(f[i][j]==m)
			{
				ans++;
			}
		}
	}
	cout<<ans;
}
