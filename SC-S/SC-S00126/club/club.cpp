#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
typedef pair<int,int> PII;
vector<PII> dp[N];
int cnt[100];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<1e5+9;i++) dp[i].clear();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				dp[i].push_back({x,j});
			}	
			if(dp[i][0].first<dp[i][2].first) swap(dp[i][0],dp[i][2]);
			if(dp[i][1].first<dp[i][2].first) swap(dp[i][1],dp[i][2]);
			if(dp[i][0].first<dp[i][1].first) swap(dp[i][0],dp[i][1]);
		}
		for(int i=1;i<=n-1;i++){
			for(int j=2;j<=n;j++){
				if(dp[j][0].first>dp[j-1][0].first)swap(dp[j][0],dp[j-1][0]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[dp[i][0].second]>=(n/2)) {ans+=dp[i][1].first;cnt[dp[i][1].second]++;}
			else {ans+=dp[i][0].first;cnt[dp[i][0].second]++;}
		}
		cout<<ans<<"\n";
	}
	return 0;
}