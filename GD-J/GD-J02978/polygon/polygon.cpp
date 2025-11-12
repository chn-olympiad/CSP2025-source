#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000001];
int n;
const int M=998244353;
int read()
{
	int k=0,l=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')l=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*l;
}
map<int,map<int,map<int,int> > > sum;
int dfs(int x,int sim,int maxn)
{
	if(x>n)
		return sim>maxn*2;
	if(sum[x][sim][maxn])
	{
		if(sum[x][sim][maxn]==-1)
			return 0;
		return sum[x][sim][maxn];
	}
	sum[x][sim][maxn]+=dfs(x+1,sim+a[x],max(maxn,a[x]));
	sum[x][sim][maxn]%=M;
	sum[x][sim][maxn]+=dfs(x+1,sim,maxn);
	sum[x][sim][maxn]%=M;
	if(sum[x][sim][maxn]==0)
	{
		sum[x][sim][maxn]=-1;
		return 0;
	}
	return sum[x][sim][maxn];
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	printf("%lld",dfs(1,0,0));
	return 0;
}

