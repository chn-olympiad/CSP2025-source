#include<bits/stdc++.h>
#define itn int
#define pb push_back
#define ll long long
#define endl '\n'
#define int ll
using namespace std;
const int MOD1=1e9+7;
const int MOD2=998244353;
const int N=5e3+5;
int n,ans,mx,a[N],fac[N];
void dfs(int i,int k,int s,int m){
	if(i==n+1){
		if(k>=3 and s>2*m){
			ans++;
			ans%=MOD2;
		}
		return;
	}
	dfs(i+1,k+1,s+a[i],max(m,a[i]));
	dfs(i+1,k,s,m);
}
inline int qpow(int a,int b,int p){
	int res=1;
	while(b){
		if(b&1)res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
inline int C(int n,int m){
	return fac[n]*qpow(fac[n-m],MOD2-2,MOD2)%MOD2*qpow(fac[m],MOD2-2,MOD2)%MOD2;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],mx=max(mx,a[i]);
	if(mx==1){
		fac[0]=1; 
		for(int i=1;i<=n;i++)
			fac[i]=fac[i-1]*i%MOD2;
		for(int i=3;i<=n;i++)
			ans=(ans+C(n,i))%MOD2;
		cout<<ans;
		return;
	}
	dfs(1,0,0,0);
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--)
		Solve();
	return 0;
}

