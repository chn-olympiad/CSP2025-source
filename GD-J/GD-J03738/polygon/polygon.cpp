#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,a[5005],sum;
void dfs(long long q,long long maxx,long long s)
{
	if(q>n)
	{
		if(s>maxx*2)sum++;
		sum=sum%MOD;
		return ;
	}
	dfs(q+1,a[q],s+a[q]);
	dfs(q+1,maxx,s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		std::cin>>a[i];
		if(a[i]==1)sum++;
	}
	if(sum==n)
	{
		long long t=1,w=2;
		sum=0;
		for(int i=3;i<=n;i++)
		{
			sum=(sum+t%MOD)%MOD;
			t=(t*2%MOD+w)%MOD,w++;
		}
		cout<<sum%MOD;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	std::cout<<sum%MOD;
	return 0;
}
