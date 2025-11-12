#include <bits/stdc++.h>
using namespace std;
/*
今年s感觉好难，我不会做wwww 
*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>>a(n,vector<int>(3));
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		vector<int>cnt(3,0);
		long long ans=0;
		vector<vector<int>>adj(3);
		for(int i=0;i<n;i++){
			int best=max({a[i][0],a[i][1],a[i][2]});
			int dep=(best==a[i][0])?0:(best==a[i][1])?1:2;
			cnt[dep]++;
			ans+=best;
			for(int j=0;j<3;j++){
				if(j!=dep){
					adj[dep].push_back(a[i][dep]-a[i][j]);
				}
			}
		}
		for(int i=0;i<3;i++){
			if(cnt[i]<=n/2)continue;
			sort(adj[i].begin(),adj[i].end());
			for(int j=0;j<cnt[i]-n/2;j++)ans-=adj[i][j];
		}
		cout<<ans<<endl;
	}
	return 0;
}

