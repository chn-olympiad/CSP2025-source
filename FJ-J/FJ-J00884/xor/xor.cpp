#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
bool v=0;
int a[N],s[N],f[N],vis[N],cnt=0,cnt2=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i=1;
	cin>>n>>k;
	cin>>a[1];
	s[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)cnt++;
		if(a[i]==0)cnt2++;
		if(a[i]>1)v=1;
		s[i]=s[i-1]^a[i];
	}
	if(a[1]==1)cnt2++;
	if(a[1]==0)cnt++;
	if(a[1]>1)v=1;
	if(k==0)
	{
		cout<<cnt2;
		return 0;
	}
	else if(v==0)
	{
		cout<<cnt;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)f[i]=0;
	int z=1,ans=0;
	for(int j=z;j<=n;j++)
		{
		//	cout<<z<<j<<ans<<endl;
			if(z==j)
			{
				if(a[z]==k)
				{
					ans++;
					z++;
					j=z-1;
			//		vis[z]=1;
				}
				else
				{
				//	if(f[i]==0)f[i]=f[i-1];
					if(j==n)
					{
						z++;j=z-1;
					}
					else continue;
				}
			}
			else
			{
			//	cout<<z<<j<<s[j];
				if(z==1&&s[j]==k)
				{
				//	cout<<f[i]<<i<<j<<endl;
					ans++;
					z++;
					j=z-1;
				}
				else if(z!=1&&int(s[j]^s[z-1])==k)
				{
					ans++;
					z++;
					j=z+(j-z);
				//	if(i==3)cout<<f[i]<<j<<endl;
				//	vis[z]=1;
				}
				else if((s[z]!=k&&z==1)||(z!=1&&s[j]^s[z-1]!=k))
				{
					/*if(f[i]==0)
					{
						f[i]=f[i-1];
					}*/
					if(j==n)
					{
						z++;j=z-1;
					}
					else continue;
				}
			}
			//cout<<f[i]<<j<<endl;
		}

	/*int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,f[i]);
	}*/
	cout<<ans;
	}
	return 0;
}
