#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e2+10;
const ll mod=998244353;
int n,m,k;
string s;
ll c[N];
ll jc[N];
ll inv[N];
ll jc_inv[N];
ll modd(ll x)
{
	return (x+mod)%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	jc[0]=jc[1]=1;
	inv[1]=1;
	jc_inv[0]=jc_inv[1]=1;
	for(int i=2;i<=N;i++)
	{
		jc[i]=modd(jc[i-1]*i);
		inv[i]=(mod-mod/i*modd(inv[mod%i]))%mod;
		jc_inv[i]=modd(jc_inv[i-1]*inv[i]); 
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];	
	} 
	cout<<jc[n];
	return 0;
}