#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500],ans;
void dfs(long long step,long long sum,long long ma){
	if(step>n){
		if(sum>ma*2) ans++;
		ans%=998244353;
		return;
	}
	dfs(step+1,sum+a[step],max(ma,a[step]));
	dfs(step+1,sum,ma);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
