#include<bits/stdc++.h>
using namespace std;
int readin()
{
	char st;
	int res=0;
	st=getchar();
	while(st>='0'&&st<='9')
	{
		res=res*10+st-'0';
		st=getchar();
	}
	return res;
}
const int mod=998244353;
int n;
int a[5005];
long long ans;
void dfs(int x,int maxn,long long h,int lenth)
{
	if(x>n)
	{
		return ;
	}
	dfs(x+1,maxn,h,lenth);
	h=h+a[x];
	if(maxn<a[x])
	{
		maxn=a[x];
	}
	lenth++;
	if(lenth>=3&&h>(maxn*2))
	{
		ans++;
		ans=ans%mod;
	}
	dfs(x+1,maxn,h,lenth);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=readin();
	for(int i=1;i<=n;i++)
	{
		a[i]=readin();
	}
	dfs(1,0,0,1);
	cout<<ans%mod;
	return 0;
}