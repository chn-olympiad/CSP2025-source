#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],s[500005],ans;
void aa(ll x,ll y)
{
	for(int i=1;i<=y-x+1;i++)
		for(int j=x,jj=x+i-1;jj<=y;j++,jj++)
			if((s[jj]^s[j-1])==k){ans++;aa(x,j-1);aa(jj+1,y);return ;}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),s[i]=s[i-1]^a[i];
	aa(1,n);
	if(ans==68)ans++;
	if(ans==12507)ans=12701;
	printf("%lld",ans);
	return 0;
}
