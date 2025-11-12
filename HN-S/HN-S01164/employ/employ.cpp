#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],ans=1,fac[N];
string s;

int qpow(int x,int k)
{
	int base=x,res=1;
	for(;k;k>>=1,base=(base*base)%mod)if(k&1) res=(res*base)%mod;
	return res;
}

int C(int x,int y){return fac[y]*qpow(fac[x]*fac[y-x]%mod,mod-2)%mod;}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=m;i<=n;i++)
	{
		ans=(ans+fac[n]*qpow(fac[n-i+1],mod-2))%mod;
	}
	cout<<(ans%mod+mod)%mod;
	return 0;
}
