#include <iostream>
#include <cstdio>

using namespace std;

long long n,k,a[500010],f[500010],g[500010];
bool ff=1;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)ff=0;
	}
	if(n<=1000)
	{
		for(long long i=1;i<=n;i++)
		{
			long long tmp=0;
			for(long long j=i;j>=1;j--)
			{
				tmp^=a[j];
				if(tmp==k)
				{
					f[i]=max(f[i],g[j-1]+1);
					break;
				}
			}
			g[i]=max(g[i-1],f[i]); 
		}
		//for(long long i=1;i<=n;i++)cerr<<f[i]<<" "; cerr<<endl;
		cout<<f[n];
	}
	else
	{
		if(ff)
		{
			long long cnt=0;
			for(long long i=1;i<=n;i++)
			{
				if(a[i]==k)cnt++;
				else if(i>1&&(a[i]!=k&&a[i-1]!=k&&(a[i]^a[i-1])==k))cnt++;
			}
			cout<<cnt;
		}
		else
		{
			for(long long i=1;i<=n;i++)
			{
				long long tmp=0;
				for(long long j=i;j>=1;j--)
				{
					tmp^=a[j];
					if(tmp==k)
					{
						f[i]=max(f[i],g[j-1]+1);
						break;
					}
				}
				g[i]=max(g[i-1],f[i]); 
			}
			//for(long long i=1;i<=n;i++)cerr<<f[i]<<" "; cerr<<endl;
			cout<<f[n];
		}
	}
}

