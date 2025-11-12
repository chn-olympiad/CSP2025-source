#include<bits/stdc++.h>
using namespace std;
long long n,k,t[1111111],ans;
int f[22222][22222],vis[1111111];
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		f[1][i]=t[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			f[i][j]=f[i-1][j]^f[1][j+(i-1)];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if(f[i][j]==k)
			{
				int flag=1;
				for(int l=j;l<=j+(i-1);l++)
				{
					if(vis[l]==1)
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					ans++;
					for(int l=j;l<=j+(i-1);l++)
					{
						vis[l]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
