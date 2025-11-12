#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,cnt0,cnt1;
string s;
void solve1(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(t!=0) cnt++;
	}
	long long ans=1;
	for(int i=1;i<=n-1;i++){
		ans=1ll*(i%mod)*(ans%mod)%mod;
	}
	ans=1ll*(ans%mod)*(cnt%mod)%mod;
	cout<<ans;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0') cnt0++;
		else cnt1++;
	}
	if(cnt1==0){
		cout<<0;
		return 0;
	}
	if(m==1) solve1();
	return 0;
}
