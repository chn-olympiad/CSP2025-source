#include <bits/stdc++.h>
using namespace std;
long long a[7005],check[7005],n,ans=0;
const long long mod=998244353;
bool pianfen=true;
void dfs(long long step,long long last,long long sum,long long cnt){
	if(step==n+1){
		if(cnt>=3&&sum>last*2) ans=(ans+1)%mod;	
	}else{
		dfs(step+1,last,sum,cnt);
		check[step]=a[step];
		dfs(step+1,a[step],sum+a[step],cnt+1);
		check[step]=0;
	}
}
long long c[5005][5005];
void init(){
	for(long long i=0;i<5002;i++) c[i][i]=1;
	for(long long i=0;i<5002;i++) c[i][0]=1;
	for(long long i=1;i<=5002;i++){
		for(long long j=1;j<i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=mod;
		}
	}
}
int main(){
	init();
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) pianfen=false;
	}
	if(pianfen){
		long long sum=0;
		for(long long i=3;i<=n;i++) sum=(sum+c[n][i])%mod;
		cout<<sum;
	}else{
		sort(a+1,a+1+n);
		dfs(1,0,0,0);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
