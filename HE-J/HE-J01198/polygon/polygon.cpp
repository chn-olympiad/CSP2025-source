#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5010];
long long b[5010],ans,isd[5010],sd[5010];
int qpow(long long a,long long b) {
	long long res=1;
	while(b){
		if(b&1)res = res*a%mod;
		a= a*a%mod;
		b>>=1;
	}
	return res;
}
void init(int x){
	sd[0] = 1;
	for(int i = 1;i <= x;i ++)sd[i]=sd[i-1]*i%mod;
	isd[x] = qpow(sd[x],mod-2);
	for(int i = x-1;i >= 1;i--) {
		isd[i] = isd[i+1]*(i+1)%mod;
	}
}
int C(int n,int m)
{
	if(n==m)return 1;
	return sd[m]%mod*isd[n]%mod*isd[m-n]%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(n == 3)
	{
		if(a[3] < a[1]+a[2])
			cout<<1;
		else 
			cout<<0;
		return 0;
	}
	if(a[n] == 1)
	{
		init(n+1);
		for(int i = 3;i <= n;i ++){
			ans = (ans+C(i,n))%mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
