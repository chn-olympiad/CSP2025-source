#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,k,ans;
long long a[500005];
long long dp[1005][1005];
long long C(int a,int b){
	long long ansa=1,ansb=1;
	for(int i=1;i<=a;i++){
		ansb=(ansb*(b-i+1))%mod;
	}
	for(int i=1;i<=a;i++){
		ansa=(ansa*(a-i+1))%mod;
	}
	return ansb/ansa;
}
void dfs(long long p,long long cnt,long long maxxx){
	if(p>n){
		if(cnt>maxxx*2) ans++;
		return ;
	}
	dfs(p+1,cnt,maxxx);
	
	dfs(p+1,cnt+=a[p],max(maxxx,a[p]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool kkk=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) kkk=1;
	}
	if(kkk==0){
		for(int j=3;j<=n;j++){
			ans=((ans-mod+C(j,n))%mod+mod)%mod;
		}
		cout<<ans<<endl;
		return 0;
	}else{
		dfs(1,0,0);
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}

