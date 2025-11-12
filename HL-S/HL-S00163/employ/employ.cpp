#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int quick_pow(int a,int b){
	int base=a,ans=1;
	while(b){
		if(b&1) ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt1=0,cnt2=0;
	cin>>n>>m;
	string s;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) if(s[i]=='0') cnt1++;
	for(int i=1,t;i<=n;i++){
		cin>>t;
		if(t==0) cnt2++;
	}
	if(m==n){
		if(cnt1||cnt2) cout<<"0";
		else{
			int ans=1;
			for(int i=1;i<=n;i++) ans=ans*i%mod;
			cout<<ans%mod;
		}
		return 0;
	}
//	if(n-cnt2<m) cout<<"0";
//	else{
//		
//	}
} 
