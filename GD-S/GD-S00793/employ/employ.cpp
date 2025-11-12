#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,c[5008],q,mod=998244353;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	k=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) {
			k--;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]<=k){
			
		}
	}
	//cout<<k<<"\n";
	if(s.find("0")==-1){
		ans=1;
		for(long long i=n;i>=1;i--){
			ans=ans*(i%mod);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
}
