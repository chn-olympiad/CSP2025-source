#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
string s;
int t;	long long n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(m==1){
		for(long long i=0;i<(long long)s.size();i++){
			if(s[i]=='1')t++;
		}
		for(long long i=1;i<=n-1;i++){
//		if(ans>=mod)ans
		ans=((ans%mod)*i)%mod;
		}
		cout<<((t%mod)*(ans%mod))%mod;
		return 0;
	}
	
	for(long long i=1;i<=n;i++){
//		if(ans>=mod)ans
		ans=((ans%mod)*i)%mod;
	}
	cout<<ans;
}
