#include<bits/stdc++.h>
using namespace std;
const int K=500005;
int n,k,a[K],u,ans,sum[K],o,l,y,t,b[K];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1)
	{
		cin>>u;
		if(u==k)
		{
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			sum[i]=a[i];
		}
		else
		{
			sum[i]=sum[i-1]^a[i];
		}
		if(a[i]==0)
		{
			o++;
		}
		if(l==0&&a[i]>1)
		{
			l=1;
		}
		if(a[i]==1)
		{
			y++;
		}
	}
	if(l==0)
	{
		if(o==0)
		{
			if(k==1)
			{
				ans=n;
			}
			cout<<ans;
			return 0;
		}
		if(y==0)
		{
			if(k==0)
			{
				ans=n;
			}
			cout<<ans;
			return 0;
		}
		if(k==0)
		{
			ans=o;
		}
		else
		{
			ans=y;
		}
		cout<<ans;
		return 0;
	}
	if(k==0)
	{
		cout<<o;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1)
		{
			continue;
		}
		for(int j=1;j<=i;j++)
		{
			if(b[j]==1)
			{
				continue;
			}
			u=sum[i]^sum[j-1];
			if(u==k&&b[i]==0&&b[j]==0)
			{
				ans++;
//				cout<<j<<" "<<i<<endl;
				for(int ii=j;ii<=i;ii++)
				{
					b[ii]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
/* 
4 0
2 1 0 3

*/
