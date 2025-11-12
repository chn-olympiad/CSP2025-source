#include<bits/stdc++.h>
using namespace std;
long long n,k,x[1000001],book[1000001],final;
bool speA=1,speB=1;
map<long long,long long> m; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>x[i];
		if(x[i]!=1)
		{
			speA=0;
		}
		if(x[i]!=1&&x[i]!=0)
		{
			speB=0;
		}
	}
	if(speA)
	{
		if(k==1)
		{
			cout<<n;
		}
		if(k==0)
		{
			cout<<n/2;
		}
		return 0;
	}
	if(speB)
	{
		if(k==1)
		{
			long long ans=0;
			for(long long i=1;i<=n;i++)
			{
				if(x[i]==1)
				ans++;
			}
			cout<<ans;
		}
		if(k==0)
		{
			long long ans=0,cnt=0;
			for(long long i=1;i<=n;i++)
			{
				if(x[i]==0)
				{
					ans++;
					ans+=cnt/2;
					cnt=0;
				}
				else
				{
					cnt++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	else
	{
		for(long long len=1;len<=n;len++)
		{
			for(long long l=1;l+len-1<=n;l++)
			{
				long long r=l+len-1;
				long long flag=0;
				for(long long i=l;i<=r;i++)
				{
					if(book[i]==1)
					{
						flag=1;
						break;
					}
				}
				if(flag==1)
				continue;
				long long ans=0;
				for(long long i=l;i<=r;i++)
				{
					ans=ans xor x[i];
				}
				if(ans==k)
				{
					final++;
					for(long long i=l;i<=r;i++)
					{
						book[i]=1;
					}
				}
			}
		}
		cout<<final;
	}
	return 0;
}

