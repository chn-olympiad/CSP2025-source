//GZ-S00109 毕节七星关东辰实验学校 周泰丞
#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,ans;
long long p[100020][3];
long long c[3];
long long dfs(long long x,long long y)
{
	c[y]++;
	if(c[y]>n/2)
	{
		c[y]--;
		return 0;
	}
	if(x==n)
	{
		c[y]--;
		return p[x][y];
	}
	long long a=dfs(x+1,0);
	long long b=dfs(x+1,1);
	long long d=dfs(x+1,2);
	c[y]--;
	return p[x][y]+max(max(a,b),d);
}
void running()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld %lld %lld",&p[i][0],&p[i][1],&p[i][2]);
	ans=max(max(dfs(1,0),dfs(1,1)),dfs(1,2));
	printf("%lld",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		running();
	}
	return 0;
} 
