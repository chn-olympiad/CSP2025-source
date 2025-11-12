#include<bits/stdc++.h>
using namespace std;
using int64=long long;
int64 n,q,ans,c[505],unzeron;
string s;
constexpr int64 MOD= 998244353;
bool _debug=false;
int main(){
	if(!_debug) {
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	unzeron=n;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			unzeron-=1;
		}
	}
	cout<<unzeron<<'\n';
	ans=1;
//	int j=unzeron;
	int j=n;
	for(int i=n;i>=1;i--){
		ans*=j;
		ans%=MOD;
//		j-=1;
//		if(i==n-q){
//			j+=(n-unzeron);
//		}
	}
	cout<<ans;
	return 0;
} 
