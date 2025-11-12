#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans=1;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char v;
		cin>>v;
		if(v=='0'){
			cout<<0;
			return 0;
		}
	}
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=mod;
		cout<<ans<<" ";
	}
	cout<<ans;
	return 0;
}
