#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int x;
int cnt;
int ans=1;
int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==0) cnt--;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=2;i--){
		ans*=(i%mod);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}

