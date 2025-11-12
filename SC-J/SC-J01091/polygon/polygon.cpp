#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
const ll M=998244353;
ll a[N],n,ma,jc[N],ans;
ll qm(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%M;
		a=a*a%M;
		b=(b>>1);
	}
	return res;
}
ll ny(ll x){
	return qm(x,M-2);
}
ll cc(ll x,ll y){
	return jc[y]*ny(jc[y-x])%M*ny(jc[x])%M;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(n<3){
		cout<<0;return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[0]>ma*2) cout<<1;
		else cout<<0;
		return 0;
	}
	jc[0]=1;
	for(int i=1;i<N;i++){
		jc[i]=jc[i-1]*i%M;
	}
	if(ma==1){
		for(int i=3;i<=n;i++)
			ans=(ans+cc(i,n)%M)%M;
		cout<<ans;
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		ll gs=0,su=0,maa=0;
		for(int j=24;j>=0;j--){
			if(((i>>j)&1)){
				gs++;
				su+=a[j];
				maa=max(maa,a[j]);
			}
		}
		if(su>(maa*2)&&gs>=3) ans++;
	}
	cout<<ans;
	return 0;
}