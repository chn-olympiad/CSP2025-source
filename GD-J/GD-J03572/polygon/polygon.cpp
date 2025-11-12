#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const ll Mod=998244353;
ll a[N],n;
ll sum;
ll combine(ll m,ll n){
	if(m*2>n) m=n-m;
	ll ans=1,sna=1;
	for(ll i=n;i>=n-m+1;i--) ans*=i;
	for(ll i=1;i<=m;i++) sna*=i;
	return ans/sna;
}
void search(ll now,ll num,ll s,ll add){
	if(now==num){
		if(add>a[s]*2) sum++;
		return;
	}
	for(ll i=s+1;i<=n;i++){
		search(now+1,num,i,add+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ll flag=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(!flag){
		for(ll i=3;i<=n;i++){
			sum+=combine(i,n);
		}
		cout<<sum%Mod;
	}else{
		sort(a+1,a+1+n);
		for(ll i=3;i<=n;i++){
			for(ll j=1;j<=n;j++){
				search(1,i,j,a[j]);
			}
		}
		cout<<sum%Mod;
	}
	return 0;
}
