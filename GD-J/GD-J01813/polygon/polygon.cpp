#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5010;
const ll MOD=998244353;
ll n,a[N],f[N],g[2*N];
ll qp(ll x){
	ll ans=1,t=2;
	while(x){
		if((x&1))ans=ans*t;
		ans=ans%MOD;
		t=t*t;
		t=t%MOD;
		x=x/2;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=0;i<=10000;i++)g[i]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		f[i]=f[i]+(qp((ll)(i-1))-g[a[i]]+MOD);
		f[i]%=MOD;
		for(int j=10000;j>=0;j--){
			if(j>=a[i])g[j]+=g[j-a[i]];
			g[j]%=MOD;
		}
	}
	cout<<f[n];
	return 0;
} 
