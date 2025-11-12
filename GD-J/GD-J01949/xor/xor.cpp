#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define sf scanf
#define pf printf
const int N=5*1e5+10,K=(1<<21)+10;
int dp[N][2],an[K],lastk[N];
ll n,k,a[N],sum;
int main()
{
	fin("xor.in");
	fout("xor.out");
	sf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		sf("%lld",&a[i]);
	}
	an[0]=1;
	for(int i=1;i<=n;i++){
		sum=sum^a[i];
		an[sum]=i+1;
		lastk[i]=an[sum^k];
	}
	for(int i=1;i<=n;i++){
		if(lastk[i]>0)dp[i][1]=max(dp[lastk[i]-1][1],dp[lastk[i]-1][0])+1;
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}

