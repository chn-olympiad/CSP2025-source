#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,st[5005][20],sum[5005],lg[5005],s;
ll ask(ll x,ll y)
{
	ll k=lg[y-x+1];
	return max(st[x][k],st[y-(1<<k)+1][k]);
}
int main()
{
	scanf("%lld",&n);
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&st[i][0]);
		sum[i]=sum[i-1]+st[i][0];
	}
	for(int j=1;j<=20;j++)for(int i=1;i+(1<<j)-1<=n;i++)st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++)for(int j=3;i+j-1<=n;j++)if(sum[i+j-1]-sum[i]>=2*ask(i,i+j-1))s++;
	printf("%lld",s);
	return 0;
}
