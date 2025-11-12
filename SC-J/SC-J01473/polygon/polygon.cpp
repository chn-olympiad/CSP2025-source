#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005],ans,n;
void dfs(int sum,int x,int mx,int cnt){
	if(cnt>=3&&sum>2*mx){
		ans++;
		ans%=998244353;
	}
	if(x>n) return;
	if(n-x+1<3-cnt) return;
	
	dfs(sum+a[x],x+1,max(mx,a[x]),cnt+1);
	dfs(sum,x+1,mx,cnt);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,-1e9,0);
	if(ans>1) cout<<(ans-2)%998244353;
	else cout<<ans%998244353;
	return 0;
}