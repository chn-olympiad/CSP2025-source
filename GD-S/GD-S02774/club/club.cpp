#include<bits/stdc++.h>
#define int long long
#define Pair pair<int,int>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN][3];
inline void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
	vector<Pair>vec[3];
	for(int i=1;i<=n;i++){
		int mx=max(max(a[i][0],a[i][1]),a[i][2]);
		if(a[i][0]==mx){
			int mn=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
			vec[0].push_back(Pair(mn,i));
		}
		else if(a[i][1]==mx){
			int mn=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
			vec[1].push_back(Pair(mn,i));
		}
		else{
			int mn=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
			vec[2].push_back(Pair(mn,i));
		}
	}
	int ans=0;
	for(int i=0;i<(int)vec[0].size();i++)ans+=a[vec[0][i].second][0];
	for(int i=0;i<(int)vec[1].size();i++)ans+=a[vec[1][i].second][1];
	for(int i=0;i<(int)vec[2].size();i++)ans+=a[vec[2][i].second][2];
	if((int)vec[0].size()>n/2||(int)vec[1].size()>n/2||(int)vec[2].size()>n/2){
		if((int)vec[0].size()>n/2){
			sort(vec[0].begin(),vec[0].end(),greater<Pair>());
			while((int)vec[0].size()>n/2){
				ans-=vec[0].back().first;
				vec[0].pop_back();	
			}
		}else if((int)vec[1].size()>n/2){
			sort(vec[1].begin(),vec[1].end(),greater<Pair>());
			while((int)vec[1].size()>n/2){
				ans-=vec[1].back().first;
				vec[1].pop_back();
			}
		}else{
			sort(vec[2].begin(),vec[2].end(),greater<Pair>());
			while((int)vec[2].size()>n/2){
				ans-=vec[2].back().first;
				vec[2].pop_back();
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int T;cin>>T;while(T--)solve();
}