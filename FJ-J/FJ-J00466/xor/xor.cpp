# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N = 505000;
ll n,k,a[N],sum[N];
ll ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]),sum[i]=sum[i-1]^a[i];
	for(int j=n;j>=1;j--) 
	for(int i=j;i>=1;i--)
	if((sum[j]^sum[i-1])==k){++ans;j=i;break;}
	cout<<ans;
}
