#include<bits/stdc++.h>
#define int long long
const int N=6e5+5;
using namespace std;
int n,a[N];
int ans = 0;
void dfs(int now,int tot,int sum,int mmax){
	if(now == n+1){
		if(tot < 3) return;
		if(mmax*2 < sum) ans++;
		return;
	}
	dfs(now+1,tot,sum,mmax);
	dfs(now+1,tot+1,sum+a[now],max(mmax,a[now]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

