#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define ull unsigned long long
using namespace std;
int n;
const int N=5e3+5e2;
int a[N];
int mx=INT_MIN;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		ull ans=0;
		for(int i=3;i<=n;i++){
			for(int j=n+1-i;j>=1;j--){
				ans=(ans%mod+(j%mod*(j+1)%mod)/2%mod)%mod;
			}
		}
		cout<<ans%mod;
		return 0;
	}
	else if(n==3&&mx<=10){
		if(a[1]+a[2]+a[3]-mx>mx){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	else if(mx==INT_MIN){
		cout<<"I AK CSP-J\n";
		cout<<"sasakure.uk is my god!\n";
		cout<<"R likes playing small gun mu.";
		return 0;
	}
	
	
	
	return 0;
}
