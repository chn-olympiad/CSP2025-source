#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	string s; cin>>s;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%MOD;
	}
	cout<<ans<<"\n";
	return 0;
}
