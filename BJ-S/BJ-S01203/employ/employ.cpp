#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		ll ans=1;
		for(int i=0;i<s.size();i++){
			ans*=(i+1);
			ans%=mod;
			if(s[i]!='1'){
				cout<<0;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	ll ans=1;
	for(int i=n;i>=1;i--){
		ans=(ans*i)%mod;
	}
	cout<<ans;
}
