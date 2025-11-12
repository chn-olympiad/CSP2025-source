#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace{
	struct node{
		int a,b,c;
	}a[200005];
	vector<int>v[3];
	void solve(){
		v[0].clear(),v[1].clear(),v[2].clear();
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c) v[0].push_back(i);
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c) v[1].push_back(i);
			else if(a[i].c>=a[i].b&&a[i].c>=a[i].a) v[2].push_back(i);
		}
		int xxx=n/2;
		if(v[0].size()>xxx){
			sort(v[0].begin(),v[0].end(),[&](int x,int y){
			return max(a[x].b,a[x].c)-a[x].a<max(a[y].b,a[y].c)-a[y].a;});
			for(int i=v[0].size()-1;i>=xxx;v[0].pop_back(),i--)
				if(a[v[0][i]].b>a[v[0][i]].c&&v[1].size()<xxx
				||v[2].size()==xxx
				||a[v[0][i]].b==a[v[0][i]].c&&v[1].size()<v[2].size()) v[1].push_back(v[0][i]);
				else v[2].push_back(v[0][i]);
		}
		if(v[1].size()>xxx){
			sort(v[1].begin(),v[1].end(),[&](int x,int y){
			return max(a[x].a,a[x].c)-a[x].b<max(a[y].a,a[y].c)-a[y].b;});
			for(int i=v[1].size()-1;i>=xxx;v[1].pop_back(),i--)
				if(a[v[1][i]].a>a[v[1][i]].c&&v[0].size()<xxx
				||v[2].size()==xxx
				||a[v[1][i]].a==a[v[1][i]].c&&v[0].size()<v[2].size()) v[0].push_back(v[1][i]);
				else v[2].push_back(v[1][i]);
		}
		if(v[2].size()>xxx){
			sort(v[2].begin(),v[2].end(),[&](int x,int y){
			return max(a[x].a,a[x].b)-a[x].c<max(a[y].a,a[y].b)-a[y].c;});
			for(int i=v[2].size()-1;i>=xxx;v[2].pop_back(),i--)
				if(a[v[2][i]].a>a[v[2][i]].b&&v[0].size()<xxx
				||v[1].size()==xxx
				||a[v[2][i]].a==a[v[2][i]].b&&v[0].size()<v[1].size()) v[0].push_back(v[2][i]);
				else v[1].push_back(v[2][i]);
		}
		int ans=0;
		for(auto i:v[0]) ans+=a[i].a;
		for(auto i:v[1]) ans+=a[i].b;
		for(auto i:v[2]) ans+=a[i].c;
		cout<<ans<<"\n";
	}
	void MAIN(){
		cin.tie(0)->sync_with_stdio(0);
		freopen("club.in","r",stdin);//对拍 11000 组无错误。CCF 真卡了只能受着了 
		freopen("club.out","w",stdout);
		int t;cin>>t;
		while(t--) solve();
	}
}
signed main(){MAIN();}
