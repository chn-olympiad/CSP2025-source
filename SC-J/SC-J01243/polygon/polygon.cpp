#include<bits/stdc++.h>
using namespace std;
int a[5001],n,mod=998244353,ans;
int c(int al,int b){
	if(b>al/2) b=al-b;
	if(b==0) return 1;
	int sum=1;
	for(int i=al;i>=al-b+1;i--){
		sum*=i;
		sum/=(al-i+1);
		sum%=mod;
	}
	return sum;
}
void dfs(int step,int tot,int all,int last){
	if(step>n && all>=3 && tot>2*a[last]){
		ans=(ans+1)%mod; 
		return;
	}
	if(step>n) return;
	dfs(step+1,tot+a[step],all+1,step);
	dfs(step+1,tot,all,last);
	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		for(int i=0;i<=n-3;i++) ans=(ans+c(n,i))%mod;
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<'\n';
	return 0;
} 