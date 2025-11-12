#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[114514],mod=1e9+7,ans,f[114514];
void dfs(long long i,long long s){
	if(i==n+1){
		long long sum=0,cnt=0;
		if(s<3) return ;
		for(int i=1;i<=n;i++){
			if(!f[i]) continue;
			cnt=max(cnt,a[i]);
			sum+=a[i];
		}
		if(sum>cnt*2) ans++;
		return ;
	}
	f[i]=1;
	dfs(i+1,s+1);
	f[i]=0;
	dfs(i+1,s);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
}
