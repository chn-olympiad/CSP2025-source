#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll n,m,ans;
const ll mod=998244353; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=100){
		cout<<0<<"\n";
		return 0;
	}
	ll cnt=0;
	for(int i=m;i<=n;++i){
		ans=1;
		for(int j=n;j>=n-i+1;--j){
			ans*=j;
			ans=(ll)(ans/(i-n+j));
		}
		cnt+=ans;
		cnt%=mod;
	}
	cout<<cnt<<"\n";
	return 0;
}
