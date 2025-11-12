#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int mg[5005];
int ans=0;

int dfs(int tot,int la,int m){
	for(int i=la+1;i<=n;i++){
		if(m>=2 && tot>mg[i]){
			ans++;
			ans %= 998244353;
		}
		dfs(tot+mg[i],i,m+1);
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>mg[i];
	sort(mg+1,mg+1+n);
	for(int i=1;i<=n-2;i++) dfs(mg[i],i,1);
	cout<<ans;
	return 0;
}