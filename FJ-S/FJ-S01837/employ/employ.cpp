#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n1[501],m1[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	ll t=1;
	for(int i=1;i<=n;i++){
		n1[i]=a[i]-'0';
//		cout<<n1[i]<<' ';
		if(n1[i]==1) t++; 
	}
	ll all=n;
	for(int i=1;i<=n;i++){
		cin>>m1[i];	
		if(m1[i]==0){
			all--;
			continue;
//			cout<<m1[i]<<endl;
		}
		if(m1[i]<=n-all){
			all--;
//			cout<<m1[i]<<endl;
		} 
	}
//	cout<<all<<endl;
	if(all<m){
		cout<<0<<endl;
		return 0;
	} 
	
	if(t==n){
		ll ans=1;
		for(int i=all;i>=all-m;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}