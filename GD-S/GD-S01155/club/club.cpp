#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n,ans=0; cin>>n;
	vector<int>f[3];
	for(int i=1,x,y,z;i<=n;++i) {
		cin>>x>>y>>z;
		int k=max({x,y,z}); ans+=k;
		if(k==x) f[0].push_back({k-max(y,z)});
		else if(k==y) f[1].push_back({k-max(x,z)});
		else f[2].push_back({k-max(x,y)});
	}
	for(int o:{0,1,2}) if((int)f[o].size()>n/2) {
		sort(f[o].begin(),f[o].end());
		for(int i=0;i<(int)f[o].size()-n/2;++i) ans-=f[o][i];
	}
	cout<<ans<<"\n";
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int _; cin>>_;
	while(_--) solve();
	return 0;
}
