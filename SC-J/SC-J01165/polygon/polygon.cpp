#include<bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
int a[5005],n;
int ans=0;
const int mod=998244353;
void dfs(int cur,int sum,int mx) {
	if(cur==n+1) {
		if(sum>mx*2) ans=(ans+1)%mod;
		return ;
	}
	dfs(cur+1,sum,mx);
	dfs(cur+1,sum+a[cur],max(mx,a[cur]));
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}