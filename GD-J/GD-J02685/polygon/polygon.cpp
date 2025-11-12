#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+10;
const ll M = 998244353;
ll n,a[N],ans;
ll fx(ll a,ll b){
	ll op=1;
	if(a==0)return 1;
	if(a==b)return 1;
	for(int i=b+1;i<=a;i++){
		op*=i;
		op%=M;
	}
	return op;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		ll op = a[1]+a[2];
		if(op>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		ans+=fx(n,i)/fx(n-i,1);
		ans%=M;
	}
	cout<<ans;
	return 0;
}
