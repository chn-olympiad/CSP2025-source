#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],s[5005],ans;
void dfs(int idx,int cnt,int maxx,int s){
	if(cnt>=3&&s>2*maxx){
		ans=(ans+1)%mod;
	}
	for(int i=idx;i<=n;i++){
		dfs(i+1,cnt+1,max(maxx,a[i]),s+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		s[i]=s[i-1]+a[i];
//		if(i>=3&&s[i-1]>a[i]) ans=(ans+1)%mod;
//	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

