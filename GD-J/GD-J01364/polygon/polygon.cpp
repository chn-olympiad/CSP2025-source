#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long  m[5005],s[5005],l[5005];
void solve(){
	long long n,h=0;
	cin>>n;
	l[0]=1;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		l[i]=(l[i-1]*i)%mod;
	}
	s[0]=1;
	for(int i=3;i<=n;i++){
		if(s[n-i]>0){
			h=(h+s[n-i])%mod;
			continue;
		}
		s[i]=l[n]/l[i]/l[n-i];
		h=(h+s[i])%mod;
	}
	cout<<h;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0; 
}
