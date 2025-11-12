#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
const long long MOD=998244353;
long long n,a[MAXN],sum;
bool cmp(int x,int y)
{
	return x>y;
}
long long find_and(long long x)
{
	return ((x+1)*x/2)%MOD;
}
long long dfs(long long ans,long long number_id,long long maxn_id)
{
	if(number_id-maxn_id>=2&&ans>a[maxn_id]*2)
		return find_and(n-(number_id-1))+1;
	if(number_id>n) return 0;
	if(maxn_id==number_id)return dfs(ans+a[number_id],number_id+1,maxn_id)%MOD;
	return (dfs(ans,number_id+1,maxn_id)+dfs(ans+a[number_id],number_id+1,maxn_id))%MOD;
	
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n); 
	for(long long i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n-2;++i)
	{
		sum=(sum+dfs(0,i,i))%MOD;
	}
	printf("%lld",sum);
	return 0;
}
