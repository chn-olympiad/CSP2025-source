#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=998244353;
/*ll fastpow(ll x,ll y,ll two=2){
	ll ans=1;
	while(y){
		if(y%two==1){
			ans=ans*y%Mod;
		}
		y=y/2;
		x=x*x%Mod;
	}
	return ans;
}*/
ll jc(ll n){
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ans=ans*i%Mod;
	}
	return ans;
}
ll t[505];
bool cmp(int x,int y){
	if(x==0||y==0)return x>y;
	return x<y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	string k;
	cin>>k;
	int a[505];
	for(int i=0;i<n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	sort(a+1,a+n+1,cmp);
	/*for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	ll sum=0,cj=1;
	for(int i=0;i<=n;i++){
		if(t[i]!=0)cj=jc(t[i])*cj%Mod;
	}
	ll cnt=1,lt=1,ans=0;
	for(int i=0;i<n;i++){
		if(k[i]=='0'||ans>=a[i]){
			ans++;
			//cout<<i<<endl;
			lt=1;
		}else{
			cnt=cnt*lt%Mod;
			lt++;
		}
	}
	/*cout<<ans<<endl;
	if(n-ans<m){
		cout<<0;
		return 0;
    }*/
    sum=sum+cnt;
    sum=sum%Mod;

	return 0;
}
//g++ -Wall -c "employ.cpp"
//g++ -Wall -o "employ" "employ.cpp"
