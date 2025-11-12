#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
int T,n,ans;
vector<int> v[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		v[0].clear(),v[0].shrink_to_fit();
		v[1].clear(),v[1].shrink_to_fit();
		v[2].clear(),v[2].shrink_to_fit();
		cin>>n;
		for(int i=1,a,b,c;i<=n;++i){
			cin>>a>>b>>c;
			if(a==max({a,b,c})) v[0].emplace_back(max(b,c)-a),ans+=a;
			else if(b==max({a,b,c})) v[1].emplace_back(max(a,c)-b),ans+=b;
			else v[2].emplace_back(max(a,b)-c),ans+=c;
		}
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end());
		sort(v[2].begin(),v[2].end());
		while((int)v[0].size()>n/2) ans+=v[0].back(),v[0].pop_back();
		while((int)v[1].size()>n/2) ans+=v[1].back(),v[1].pop_back();
		while((int)v[2].size()>n/2) ans+=v[2].back(),v[2].pop_back();
		cout<<ans<<endl;
	}
	return 0;
}
