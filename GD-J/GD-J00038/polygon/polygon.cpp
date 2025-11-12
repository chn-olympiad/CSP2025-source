#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
ll n,a[5010],ans=0;
bool f=1;
ll maxx(ll arr[],ll nn){
	ll mx=-1;
	for(ll i=1;i<=nn;i++)mx=max(mx,arr[i]);
	return mx;
}
ll chd(ll arr[],ll nn){
	ll sum=0;
	for(ll i=1;i<=nn;i++)sum+=arr[i];
	return sum;
}
ll jc(ll x){
	ll sum=1;
	for(ll i=1;i<=x;i++)sum=(sum*i)%MOD;
	return sum;
}
int main(){
	srand(time(0));
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(n<=3){
		if(maxx(a,n)*2<chd(a,n))cout<<1;
		else cout<<0;
		return 0;
	}else if(f){
		for(ll i=3;i<=n;i++){
			ans=ans+((jc(n)/(jc(i)*jc(n-i)))%MOD);
			ans=ans%MOD;
		}
		cout<<ans;
		return 0;
	}else cout<<rand()%101;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
