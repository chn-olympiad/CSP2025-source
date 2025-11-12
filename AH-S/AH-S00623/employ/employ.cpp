#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=1;
long long n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	for(long long i=n;i>=m;i--){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}
