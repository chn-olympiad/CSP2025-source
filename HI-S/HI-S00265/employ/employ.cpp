#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=998244353;
int n,m;
string a;
int b[501],c[501],d[501];
bool p[501];
unsigned long long ans;
void comp()
{
	int fail=0,sum=0;
	for(int i=0;i<n;i++)
	{
		if(fail<d[i+1]&&a[i]=='1')
		{
			sum++;
		}
		else
		{
			fail++;
		}
	}
	if(sum>=m)
	{
		ans++;
	}
}
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)
		{
			if(x==n)
			{
				b[x]=i;
				for(int j=1;j<=n;j++)
				{
					d[j]=c[b[j]];
				}
				comp();
			}
			else
			{
				b[x]=i;
				p[i]=1;
				dfs(x+1);
				b[x]=0;
				p[i]=0;
			}
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	bool A=true;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0')
		{
			A=false;
			break;
		}
	}
	dfs(1);
	if(A)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				sum++;
			}
		}
		ans=1;
		for(unsigned long long i=n-sum;i>=1;i--)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	ans%=mod;
	cout<<ans;
	return 0;
}

