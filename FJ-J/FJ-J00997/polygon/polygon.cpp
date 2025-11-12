#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ma,sum,s,x;
long long dp[10005];
long long y[5005][15];
void dfs(int now,long long su,bool f){
	if(s>su*2&&x>=3){
		sum+=f;
		sum%=mod;
	}
	if(now>n) return;
	s+=a[now];
	x++;
	dfs(now+1,a[now],1);
	s-=a[now];
	x--;
	dfs(now+1,su,0);
}
long long qpow(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1){
			res=res*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,0);
		cout<<sum;	
	}else if(ma==1){
		y[0][0]=1;
		for(int i=1;i<=n;i++){
			y[i][0]=1;
			//cout<<y[i][0]<<' ';
			for(int j=1;j<=min(i,4);j++){
				y[i][j]=(y[i-1][j]+y[i-1][j-1])%mod;
				//cout<<y[i][j]<<' ';
			}
			//cout<<'\n';
		}
		long long ans=(qpow(2,n)-y[n][0]-y[n][1]-y[n][2]+mod*3)%mod;
		cout<<ans;
	}else{
		dp[0]=1;
		for(int i=1;i<=n;i++){
			long long val=0;
			for(int j=ma*2+1;j>=1;j--){
				if(j>=a[i]){
					dp[j]+=dp[j-a[i]];
					if((a[i]*2+1)==j){
						sum+=dp[j-a[i]];
						sum%=mod;
					}
					dp[j]%=mod;
				}else if(j<a[i]){
					dp[j]+=dp[0];
					dp[j]%=mod;
				}
			}
			dp[0]*=2;
			/*for(int i=0;i<=ma*2+1;i++){
				cout<<dp[i]<<' ';
			}
			cout<<'\n';*/
		}
		cout<<sum;
	}
	return 0;
} 
