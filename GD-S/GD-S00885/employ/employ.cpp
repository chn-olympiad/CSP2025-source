#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
bool f[505],pd=true;
bool s[505];
long long b[505],a[505];
long long w[505];
void work(long long k)
{
	if(k>n)
	{
		long long t=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]<=0)
			{
				for(int j=i+1;j<=n;j++)
				{
					b[j]--;
				}
				continue;
			}
			if(s[i]==0)
			{
				b[i]=0;
				for(int j=i+1;j<=n;j++)
				{
					b[j]--;
				}
				continue;
			}
			if(s[i]==1)t++;
		}
		if(t>=m)
		{
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])continue;
		b[k]=a[i];
		w[k]=i;
		f[i]=true;
		work(k+1);
		b[k]=0;
		w[k]=0;
		f[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char o;
		cin>>o;
		if(o=='1')s[i]=1;
		else s[i]=0,pd=false;
	}
	if(pd)
	{
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	work(1);
	cout<<ans;
	return 0;
}
