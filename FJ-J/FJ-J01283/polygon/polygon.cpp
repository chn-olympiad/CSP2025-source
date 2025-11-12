#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
ll a[N],c[N*N],num[N*N],power[N],mod=998244353;
int n;
ll mxnum;
ll lowbit(ll x)
{
	return x&(-x);
}
void add(ll x,ll k)
{
	for(;x<=5000;x+=lowbit(x)) c[x]+=k,c[x]%=mod;
}
ll query(ll x)
{
	ll ans=0;
	for(;x;x-=lowbit(x)) ans+=c[x],ans%=mod;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	power[0]=1;
	for(int i=1;i<=n;i++) cin >> a[i],mxnum=max(mxnum,a[i]),power[i]=power[i-1]*2%mod;
	sort(a+1,a+n+1);
	ll ans=0;
	num[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=3) ans+=power[i-1]-1-query(a[i]),ans%=mod;
		for(int j=mxnum-a[i];j>=0;j--)
		{
			if(num[j]) 
			{
				add(j+a[i],num[j]);
				num[j+a[i]]+=num[j];
			}
		}
	}
	cout << ans;
	return 0;
} 
