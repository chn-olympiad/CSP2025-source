#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll plusi(ll k,ll w){
	ll re=1;
	for(ll i=0,p=w;i<w-k;i++,p--){
		re*=p;
	}
	for(ll i=1;i<=k;i++){
		re/=i;
	}
	return re;
}
ll p[5005];
ll pq[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll a,sum=0;
	cin>>a;
	for(ll i=1;i<=a;i++){
		cin>>p[i];
	}
	pq[1]=p[1];
	sort(p,p+a);
	for(ll i=2;i<=a;i++){
		pq[i]=pq[i-1]+p[i];
	}
	for(ll i=3;i<=a;i++){
		for(ll i1=i;i1>=1;i1--){
			ll max=-1;
			for(ll i2=i1-1;i2>=1;i2--){
				ll pre=pq[i1]-pq[i2-1];
				if(pre>2*p[i]){
					max=i1-i2;
					sum=(sum+plusi(i-max-1,max))%998244353;	
				}
			}
		}
	}
	cout<<sum;	
	return 0;
}	
