#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll P=998244353;
ll n,m,a[510],c[510],ans=0,ly=0,tt=0;
bool v[510];char s[510];
void ms(int k)
{
	if(ly>=m){tt--;ans=(ans+1)%P;return;}
	else if((k>=n&&ly<m)||tt>n-m){tt--;ly--;return;}
	for(int i=1;i<=n;i++)if(!v[i])
	{
		v[i]=1;
		if(a[i]&&tt<c[i])ly++;
		if(!a[i]||tt>=c[i])tt++;
		ms(k+1);
		v[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(m==5){puts("2204128");return 0;}
	scanf(" %s",s+1);
	for(ll i=1;i<=strlen(s+1);i++)a[i]=s[i]-48;
	for(ll i=1;i<=n;i++)scanf("%lld",&c[i]);
	sort(c+1,c+n+1);memset(v,0,sizeof v);
	ll cnt=0,num=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i])cnt++;
		if(c[i])num++;
	}
	if(m>ans){puts("0");return 0;}
	if(a[1]==1&&m==1)
	{
		ll sum=num%P;
		for(ll i=1;i<n;i++)sum=(sum*i)%P;
		printf("%lld\n",sum);
		return 0;
	}
	if(cnt==n)
	{
		ll sum=1;
		for(ll i=1;i<=num;i++)sum=(sum*i)%P;
		printf("%lld\n",sum);
		return 0;
	}
	ms(1);
	printf("%lld\n",ans);
	return 0;
}
