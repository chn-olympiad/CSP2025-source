#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=5000+1;
ll ans;
int n,a[N];
ll dp[N*N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=3){
		int mx=0;
//		for(ll i=1;i<=5000*5000;i++){
//			dp[i]=dp[]
//		}
	}
	else {
		cout<<ans;
		return 0;
	}
	cout<<ans%998244353;
	return 0;
}
