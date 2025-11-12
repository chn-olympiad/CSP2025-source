#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MOD=998244353;
int n,a[5010];
long long ans;

void dfs(int step,int sum,int last)
{
	if(step>n)
	{
		if(sum>2*a[last]) ans++;
		return;
	}
	dfs(step+1,sum+a[step],step);
	dfs(step+1,sum,last);
}

long long poww(int a,int b)
{
	if(b==1) return (long long)a%MOD;
	if(b%2==0) return (long long)poww(a,b/2)%MOD*poww(a,b/2)%MOD;
	else return (long long)a%MOD*poww(a,b/2)%MOD*poww(a,b/2)%MOD;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]==1) 
	{
		printf("%lld\n",(long long)(poww(2,n)-1-n-(n*(n-1)/2)%MOD+MOD)%MOD);
	}
	else 
	{
		dfs(1,0,0);
		printf("%lld\n",(long long)ans%MOD);
	}	
	return 0;
}
