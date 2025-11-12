#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll n,m,c[510];
bool f1=true;
string s;

void fun1(){
	int ans=1;
	for(ll i=2;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m; cin>>s;
	for(ll i=1;i<=n;i++) cin>>c[i];
	for(ll i=0;i<(ll)(s.size());i++){
		if(s[i]=='0'){f1=false; break;}
	}
	if(f1) fun1();
	else if(m==n) cout<<0;
	return 0;
}
