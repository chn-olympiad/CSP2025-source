#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
struct node{
	int name,id,val;
};
vector<node> v;
bool cmp(node x,node y){
	return x.val < y.val;
}
int a[N][4],cnt[5],vis[N],dp[207][207][207];
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n <= 200){
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				for(int c1 = 0;c1 <= min(i,n/2);c1++){
				for(int c2 = 0;c2 <= min(i,n/2) && c1+c2 <=n ;c2++){
					int c3 = i-c1-c2;
					if(c3 > min(i,n/2)) continue;
					if(c1 != 0) dp[c1][c2][c3] = max(dp[c1][c2][c3],dp[c1-1][c2][c3]+a[i][1]);
					if(c2 != 0) dp[c1][c2][c3] = max(dp[c1][c2][c3],dp[c1][c2-1][c3]+a[i][2]);
					if(c3 != 0) dp[c1][c2][c3] = max(dp[c1][c2][c3],dp[c1][c2][c3-1]+a[i][3]);
				}}
			}
			sort(v.begin(),v.end(),cmp);
			int ans = 0;
			for(int c1 = 0;c1 <= n/2;c1++){
			for(int c2 = 0;c2 <= n/2 && c1+c2 <= n;c2++){
				int c3 = n - c1 - c2;
				if(c3 > n/2) continue;
				ans = max(ans,dp[c1][c2][c3]);
			}}
			cout<<ans<<"\n";
		}
		else{
			int ans = 0;
			for(int i=1;i<=n;i++){
				int x,y,z;
				cin>>x>>y>>z;
				v.push_back({i,1,x});
				v.push_back({i,2,y});
				v.push_back({i,3,z});
			}
			sort(v.begin(),v.end(),cmp);
			for(auto i:v){
				if(vis[i.name] || cnt[i.id] >= n/2) continue;
				ans += i.val;
				vis[i.name] = 1;
				cnt[i.id]++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
