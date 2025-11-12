#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin>>n;
	vector<tuple<int,int,int> > a(n);
	for(auto &[x,y,z]:a)cin>>x>>y>>z;
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++){
		auto &[x,y,z]=a[i];
		if(max({x,y,z})==x){
			mp[1].emplace_back(i);
		}else if(max({x,y,z})==y){
			mp[2].emplace_back(i);
		}else{
			mp[3].emplace_back(i);
		}
	}
	int ans=0;
	for(auto &x:mp[1]){
		auto [xx,y,z]=a[x];
		ans+=xx;
	}
	for(auto &x:mp[2]){
		auto [xx,y,z]=a[x];
		ans+=y;
	}
	for(auto &x:mp[3]){
		auto [xx,y,z]=a[x];
		ans+=z;
	}
	if(mp[1].size()<=n/2&&mp[2].size()<=n/2&&mp[3].size()<=n/2){
		cout<<ans<<"\n";
	}else {
		for(int i=1;i<=3;i++){
			if(mp[i].size()>n/2){
				sort(mp[i].begin(),mp[i].end(),[&](int aa,int b){
					auto [x,y,z]=a[aa];
					auto [xx,yy,zz]=a[b];
					if(i==1)return min(abs(x-y),abs(x-z))<min(abs(xx-yy),abs(xx-zz));
					if(i==2)return min(abs(x-y),abs(y-z))<min(abs(xx-yy),abs(yy-zz));
					if(i==3)return min(abs(y-z),abs(x-z))<min(abs(yy-zz),abs(xx-zz));
				});
				for(int j=0;j<mp[i].size()-n/2;j++){
					auto [x,y,z]=a[mp[i][j]];
					if(i==1)ans-=min(abs(x-y),abs(x-z));
					if(i==2)ans-=min(abs(x-y),abs(y-z));
					if(i==3)ans-=min(abs(y-z),abs(x-z));
				}
			} 
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
} 
