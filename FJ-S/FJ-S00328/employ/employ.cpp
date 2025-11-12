#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=510,mod=998244353;
int n,m,res,s[N],c[N],flag[N],k[N];
void dfs(int u)
{
	if(u==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			if(!s[i]||sum>=c[k[i]])sum++;
		if(n-sum>=m)res=(res+1)%mod;
	}
	for(int i=1;i<=n;i++)
		if(!flag[i])
		{
			flag[i]=1;
			k[u]=i;
			dfs(u+1);
			flag[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	char op[N];
	scanf("%s",&op);
	for(int i=1;i<=n;i++)s[i]=op[i-1]-'0';
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(n!=m)dfs(1);
	else
	{
		bool flag=true;
		for(int i=1;i<=n;i++)if(s[i]=='0')flag=false;
		if(flag)dfs(1);
	}
	printf("%d",res);
	return 0;
}
