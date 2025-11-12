#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[505],f,ret,res=1;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		if(c[i]==0) ret++;
	}
	if(n-ret<m) {
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size();i++) {
		if(s[i]=='0') f=1;
	}
	if(f==0) {
		for(int i=1;i<=n-ret;i++) {
			res=res*i%mod;
		}
		cout<<res;
	}
}

