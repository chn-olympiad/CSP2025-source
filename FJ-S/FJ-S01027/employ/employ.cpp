#include<bits/stdc++.h>
using namespace std;
constexpr int mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	string s; cin>>s;
	int mul=1;
	while(n--){
		int c; cin>>c;
		if(c!=0) mul=abs((mul%mod*c%mod))%mod;
	}
	cout<<mul<<"\n";
	return 0;
}
