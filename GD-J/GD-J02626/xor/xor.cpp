#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],n,k;
bool check(int x,int y)
{
	ll ans=0;
	for(int i=x;i<=y;i++)ans+=ans^a[i];
	if(ans==k)return 1;
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ll ans=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if(check(l,r))ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
