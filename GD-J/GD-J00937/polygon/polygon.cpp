#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[5005],sum;
ll chen(ll n1,ll m){
	ll sum1=1,sum2=1,sum3=1;
	for(int i=1;i<=n1;i++){
		sum1*=i;
		sum1%=998244353;
	}
	for(int i=1;i<=m;i++){
		sum2*=i;
		sum2%=998244353;
	}
	for(int i=1;i<=n-m;i++){
		sum3*=i;
		sum3%=998244353;
	}
	ll ans=sum1/(sum2*sum3);
	return ans;
}
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		ll mx=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			mx=max(a[i],mx);
		}
		if(n==3&&sum>2*mx){
			cout<<1;
		}
		else cout<<0;
	}
	else{
	    for(ll i=3;i<=n;i++){
		    sum+=chen(n,i);
	    }
	    cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
