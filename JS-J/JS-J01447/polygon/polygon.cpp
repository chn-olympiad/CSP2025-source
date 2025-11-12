#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
ll n,a[5005],b[5005],res,___mx=-1e18;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void _wr(ll x)
{
	if(x>9)_wr(x/10);
	putchar(x%10+48);
}
void write(ll x,char f='_')
{
	if(x<0)putchar('-');
	x=abs(x);
	_wr(x);
	if(f!='_')cout<<f;
}
ll qpow(ll aa,ll b,ll c=M)
{
	ll jt=1;
	aa%=c;
	while(b)
	{
		if(b&1)jt=jt*aa%c;
		aa=aa*aa%c;
		b>>=1;
	}
	return jt;
}
ll minu(ll u,ll v,ll mod=M)
{
	return (u-v+mod)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++)a[i]=read(),___mx=max(___mx,a[i]);
	if(___mx==1)
	{
		cout<<minu(minu(qpow(2,n),n),n*(n-1)/2+1);
		return 0;
	}
	for(int i=7;i<1<<n;i++)
	{
		ll cnt=0,mx=-2e9,as=0;
		for(int j=0;j<n;j++)if(i>>j&1)cnt+=a[j],mx=max(mx,a[j]),as++;
		mx<<=1;
		if(cnt>mx&&as>=3)res=(res+1)%M;
	}
	cout<<res;
	return 0;
}