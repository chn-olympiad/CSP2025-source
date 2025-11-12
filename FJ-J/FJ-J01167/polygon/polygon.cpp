#include<bits/stdc++.h>
using namespace std;
constexpr int N=5005, mod=998244353;

int n,ans,cnt,a[N];

void dfs(int x,int sum,int ma){
	if(x==n){
		if(sum>2*ma && cnt>=3) ans=(ans+1)%mod;
		return;
	}
	if(n-x<3-cnt) return; // 即使后面都选也到不了3次
	// 选
	cnt++; // 选x+1, 次数+1
	dfs(x+1,sum+a[x+1],max(ma,a[x+1]));
	// 不选
	cnt--; // 不选x+1, 次数-1
	dfs(x+1,sum,ma);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans<<"\n";
	return 0;
}
