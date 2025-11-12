#include<bits/stdc++.h>
using namespace std;//give me 20 points ku da sa i
int n,m;
const long long mod=998244353;
string s;
int akira;
long long ans=1;
int c[114514];
void solve(){
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			n--;
			akira++;
		}
	}
	for(int i=0;i<m;i++){
		ans*=n;
		n--;
	}
	cout<<ans%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	return 0;
}
