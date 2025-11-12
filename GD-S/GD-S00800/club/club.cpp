#include<bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int N = 1e5+7;

int n,_,a[N][4];
ll maxn;

void dfs(int cur,int sa,int sb,int sc,ll sum){
	if(cur == n+1){
		maxn = max(maxn,sum);
		return;
	}
	if(sa + 1 <= n/2){
		dfs(cur+1,sa+1,sb,sc,sum + 1LL*a[cur][1]);
	}
	if(sb + 1 <= n/2){
		dfs(cur+1,sa,sb+1,sc,sum + 1LL*a[cur][2]);
	}
	if(sc + 1 <= n/2){
		dfs(cur+1,sa,sb,sc+1,sum + 1LL*a[cur][3]);
	}
}

void solve(){
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	maxn = -1;
	dfs(1,0,0,0,0);
	cout<<maxn<<'\n';
}

int main(){freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
