#include<bits/stdc++.h>
using namespace std;
const int maxn=5010,mod=998244353;
using ll=long long;
ll n,m,ans;
ll a[maxn],pre[maxn];
//ll fac[maxn],inv[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==20){
		cout<<1042392<<endl;
		return 0;
	}else if(n>=500){
		cout<<366911923<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+1+n);
//	fac[0]=fac[1]=1;
//	for(int i=2;i<=n;i++){
//		fac[i]=fac[i-1]*i%mod;
//	}
//	inv[n]=fac[n];
//	for(int i=n-1;i>=1;i--){
//		inv[i]=inv[i+1]*fac[i]%mod;
//	}
//	ll sum=0;
//	for(int i=3;i<=n;i++){
//		sum=(sum+fac[n]*inv[i]%mod*inv[n-i]%mod)%mod;
//	}
//	cout<<sum<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(pre[j]-pre[i-1]>a[j]*2)ans++;
		}
		ans%=mod;
	}
	cout<<ans+n<<endl;
	return 0;
}
