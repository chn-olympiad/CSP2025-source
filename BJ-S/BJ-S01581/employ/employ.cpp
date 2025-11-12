#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,m,a[505],b[505];
long long mm;
bool f[505];
string s;
long long c(int x)
{
	long long y=1;
	for(int i=2;i<=x;i++) y=y*i%mod;
	return y;
}
bool check()
{
	int bu=0;
	for(int i=1;i<=n;i++)
	{
		if(bu<a[b[i]]&&s[i-1]=='1');
		else bu++;
	}
	if(n-bu>=m) return 1;
	return 0;
}
void dfs(int x)
{
	if(x>n)
	{
		if(check()) mm++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			b[x]=i;
			f[i]=1;
			dfs(x+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		int num=0,x=0;
		long long ans=1;
		sort(a+1,a+n+1);
		int r=0;
		for(int i=1;i<n;i++)
		{
			if(s[i]=='1')//1jiandan
			{
					num++;
					while(a[r+1]<=x&&r<n) r++;
					if(num==1) ans=ans*r%mod;
					else ans=ans*(r-1)%mod;
				
			}
			else x++;
		}
		printf("%lld",c(n)-ans*c(n-num)%mod);
	}
	else if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				printf("0\n");
				break;
			}
		}
		printf("%lld\n",c(n));
	}
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') x++;
	}
	if(x==0)//A
	{
		printf("%lld\n",c(n));
		return 0;
	}
	dfs(1);
	printf("%lld\n",mm%mod);
	return 0;
}
