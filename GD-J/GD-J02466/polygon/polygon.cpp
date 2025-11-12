#include<iostream>
#define ll long long
using namespace std;
const int MAXN=5e3+10;
int n;
int a[MAXN],MXA,ans,cnt1;
const int mod=998244353;
ll qp(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1){
			ans=ans*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		MXA=max(MXA,a[i]);
	}
	if(n>20&&MXA<=1){
		cout<<(qp(2,n)-n-n*(n-1)/2-1ll+mod)%mod<<endl;
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		int sum=0,mx=0,m=0;
		for(int k=0;k<n;k++){
			if((1<<k)&i){
				sum+=a[k];
				mx=max(a[k],mx);
				m++;
			}
		}
		if(m>=3&&sum>2*mx){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
