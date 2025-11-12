#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],sum=1,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=n;i>=1;i--){
		sum=(sum%mod)*(i%mod)%mod;
	}
	cout<<sum;
	return 0;
}
