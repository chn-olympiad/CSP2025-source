#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],ans;
long long n;
long long fpow(long long d,long long z)
{
	if(z==1)return d;
	if(z==0)return 1;
	return fpow(d,z/2)*fpow(d,z/2)*(z%2==0?1:d);
}
void dfs(long long i,long long sum,long long maxx,long long t)
{
	if(i<=n&&sum>2*maxx&&t)
	{
		ans+=fpow(2,n-i+1)/2;
		ans%=998244353;
		return;
	}
	if(b[n]-b[i]+sum<=2*maxx)return;
	if(i<=n&&sum>2*maxx&&t)ans++,ans%=998244353;
	if(i>n)return;
	dfs(i+1,sum+a[i+1],max(maxx,a[i+1]),1);
	dfs(i+1,sum,maxx,0);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1,greater<long long>());
	for(long long i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	for(long long i=1;i<=n;++i);
	dfs(1,a[1],a[1],1);
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
