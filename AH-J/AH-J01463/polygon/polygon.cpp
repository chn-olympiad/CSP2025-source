#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans,mod=998244353;
void dfs(int x,int d,long long s,long long maxx){
	if(x==n+1){
		if(s>maxx*2&&d>=3){
			ans++;
		}
		return ;
	}
	dfs(x+1,d+1,s+a[x],max(maxx,a[x]));
	dfs(x+1,d,s,maxx);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n;
	long long m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(m>1){
		dfs(1,0,0,0);
		cout<<ans%mod;
	}
	if(m==1){
		long long s=1;
		for(int i=1;i<=n;i++){
			s*=2;
			s%=mod;
		}
		ans=s-1-n-n*(n-1)/2;
		cout<<ans%mod;
	}
	return 0;
}
