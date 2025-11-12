#include<bits/stdc++.h>
using namespace std;
int p[505],sum,fl[505],n,m;
string s;
long long dfs(int cnt,int num)
{
	if(num>=m)
	{
		long long res=1;
		for(int i=1;i<=cnt;i++)
		{
			res*=i;
		}
		return res;
	}
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		if(s[cnt-1]=='0') sum--;
		if(fl[i]||p[i]<=sum) continue;
		fl[i]=1;
		res+=dfs(cnt-1,num+s[cnt-1]-'0');
		fl[i]=0;
	}
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int mn=n+1;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		mn=min(mn,p[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') sum++;
	}
	if(sum<mn)
	{
		long long ji=1;
		for(int i=1;i<=n;i++)
		{
			ji=(ji*i)%998244353;
		}
		printf("%lld",ji);
		return 0;
	}
	if(m==n)
	{
		printf("0");
		return 0;
	}
	if(n<=10)
	{
		printf("%lld",dfs(n,0));
		return 0;
	}
	return 0;
}