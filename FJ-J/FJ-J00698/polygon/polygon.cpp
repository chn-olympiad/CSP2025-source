






#include<bits/stdc++.h> 
using namespace std;
long long n,a[5005],ans,vis[5005],mx,su,mod=998244353;

/*void c(){
	cout<<n;
	for(int i=1;i<=n;++i)dp[i][a[i]][a[i]]=1;
	for(int i=1;i<=n;++i){
		su+=a[i];
		for(int j=a[i];j<=su;++j){
			for(int k=a[i];k<=mx;++k){
				dp[i][j][k]+=dp[i-1][j-a[i]][k];
				dp[i][j][k]+=dp[i-1][j][k];
				dp[i][j][k]%=mod,cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
			}
			for(int k=1;k<a[i];++k){
				dp[i][j][a[i]]+=dp[i-1][j-a[i]][k];
				dp[i][j][a[i]]%=mod,cout<<i<<' '<<j<<' '<<a[i]<<' '<<dp[i][j][a[i]]<<'\n';
			}
			
		} 
		for(int j=1;j<a[i];++j){
			for(int k=1;k<=mx;++k)dp[i][j][k]+=dp[i-1][j][k],dp[i][j][k]%=mod,cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
			
		}
	}
	for(int j=1;j<=su;++j)
	for(int k=1;k<=mx;++k){
		if(2*j>k){
			ans+=dp[n][j][k];
			
			ans%=998244353;
		}
	} 
	cout<<ans;
}*/
long long p(long long x,long long y,long long p=998244353){
	long long ans=1,tmp=x;
	while(y){
		if(y&1)ans*=tmp,ans%=p;
		tmp*=tmp;
		tmp%=p;
		y>>=1;
//		cout<<ans<<' '<<tmp<<'\n';
	} 
	return ans;
}
void print(){
	for(int i=1;i<=n;++i){
		if(vis[i])cout<<i<<' ';
	}
	cout<<'\n';
}
void dfs(long long t,long long s,long long m){
	if(t==n+1){
		if(s>m*2)++ans/*,print()*/;
		ans%=998244353;
		return;
	}
	dfs(n+1,s,m);
	for(int i=t;i<=n;++i){
		vis[i]=1;
		dfs(i+1,s+a[i],max(m,a[i]));
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		cout<<(p(2,n))-n*(n-1)/2%mod-n-1<<'\n';
		cout<<((p(2,n)-n*(n-1)/2%mod-n-1)%mod+mod)%mod;
		return 0; 
	}
	
	dfs(1,0,0);
	cout<<ans;
}
