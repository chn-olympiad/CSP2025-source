#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int n,m,sum;
string s;

signed main( ){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		if(a>0) sum++;
	}
	if(sum<m) cout<<0;
	else{
		int ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod;
	}
	return 0;
}
