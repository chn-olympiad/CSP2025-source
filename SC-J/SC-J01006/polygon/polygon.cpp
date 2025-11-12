#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,a[5005],dp[5005][5005],ans;
void dfs(int cur,int sum,int cnt,int ed){
	if(cur==n+1){
		if(cnt<3||sum<=2*ed)return;
		ans++;
		ans%=MOD;
		return;
	}
	dfs(cur+1,sum+a[cur],cnt+1,a[cur]);
	dfs(cur+1,sum,cnt,ed);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)ok=0;
	}
	if(ok){
		for(int i=3;i<=n;i++){
			int x=1,y=1;
			for(int j=1;j<=i;j++){
				x*=(n-j+1);
				y*=j;
			}
			ans+=x/y;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}