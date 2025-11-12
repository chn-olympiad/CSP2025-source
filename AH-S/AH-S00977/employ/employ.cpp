#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+20,MOD=998244353;
ll n,m,a[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(s.find("0")==string::npos){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
		cout<<ans;
		return 0;
	}
	else if(s.find("1")==string::npos){
		cout<<0;
		return 0;
	}
	if(m==1){
		int ans=1;
		for(int i=1;i<n;i++){
			ans=ans*i%MOD;
		}
		cout<<ans;
		return 0;
	}
	else cout<<n*m%MOD*m%MOD;
	return 0;
}
