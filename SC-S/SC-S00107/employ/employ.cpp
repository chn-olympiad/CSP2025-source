#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long ans;
long long decttt;
long long inv(long long t){
	long long u=1;
	while(t!=1){
		u=(u*((MOD/t)+1))%MOD;
		t=(t*((MOD/t)+1))%MOD;
	}
	return u;
}
long long dp[505][505][505];
long long fac[505],infac[505];
int q[505];
int cnt[505],sum[505];
long long ccc[505][505];
long long aaa[505][505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	fac[0]=1;
	infac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%MOD;
		infac[i]=(infac[i-1]*inv(i))%MOD;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			aaa[i][j]=(fac[i]*infac[j])%MOD;
			ccc[i][j]=(aaa[i][j]*infac[i-j])%MOD;
		}
	}
	dp[0][0][0]=1;
	char x;
	while((x!='0')&&(x!='1')){
		x=getchar();
	}
	for(int i=1;i<=n;i++){
		if(x=='0'){
			q[i]=0;
		}else{
			q[i]=1;
		}
		x=getchar();
	}
	for(int i=1;i<=n;i++){
		int r;
		cin>>r;
		cnt[r]++;
	}
	sum[0]=cnt[0];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+cnt[i];
	}
	for(int k=0;k<=n-1;k++){
		for(int s=0;s<=k;s++){
			for(int t=0;t<=k;t++){
				if(dp[k][s][t]==0){
					continue;
				}
				if(q[k+1]==1){
					dp[k+1][s+1][t]+=dp[k][s][t];
					dp[k+1][s+1][t]=dp[k+1][s+1][t]%MOD;
					for(int r=0;r<=k-t;r++){
						if(r>cnt[k-s+1]){
							break;
						}
						if(sum[k-s]<=t){
							break;
						}
						dp[k+1][s][t+r+1]+=((((sum[k-s]-t)*ccc[k-t][r])%MOD)*aaa[cnt[k-s+1]][cnt[k-s+1]-r]%MOD*dp[k][s][t])%MOD; 
						dp[k+1][s][t+r+1]=dp[k+1][s][t+r+1]%MOD;
					}
				}else{
					for(int r=0;r<=k-t;r++){
						if(r>cnt[k-s+1]){
							break;
						}
						decttt=((ccc[k-t][r]*aaa[cnt[k-s+1]][cnt[k-s+1]-r])%MOD*dp[k][s][t])%MOD;
						dp[k+1][s][t+r]=(decttt+dp[k+1][s][t+r])%MOD;
						if(sum[k-s+1]>t+r){
							dp[k+1][s][t+r+1]=((sum[k-s+1]-t-r)*decttt+dp[k+1][s][t+r+1])%MOD;
						}
					}
				}
			}
		}
	}
	/*for(int k=0;k<=n;k++){
		for(int s=0;s<=n;s++){
			for(int t=0;t<=n;t++){
				cout<<dp[k][s][t]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}*/
	for(int s=m;s<=n;s++){
		ans+=(dp[n][s][sum[n-s]])*fac[n-sum[n-s]];
		ans=ans%MOD;
	}
	cout<<ans;
	return 0;
}