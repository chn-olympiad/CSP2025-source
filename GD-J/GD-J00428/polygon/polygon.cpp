#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005][10010][2],mx=INT_MIN,f[5005][10010],mp[5005],ma[5005];
const int mod=998244353;
int zhs[5005][5005];
void Init(){
	zhs[0][0]=1;
	for(int i=1;i<=5000;i++){
		for(int j=0;j<=i;j++){
			if(j-1<0) zhs[i][j]=zhs[i-1][j];
			else zhs[i][j]=(zhs[i-1][j]+zhs[i-1][j-1])%mod;
		}
	}
}
int C(int a,int b){
	return zhs[a][b];
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	system("fc out.out polygon4.ans");
//	freopen("polygon4.in","r",stdin);
//	freopen("out.out","w",stdout);
	Init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	mx*=2;
	mx++;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		mp[a[i]]++;
		ma[i]=mp[a[i]];
	}
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=mx;j++){
			dp[i+1][j][0]+=(dp[i][j][1]+dp[i][j][0])%mod;
			dp[i+1][j][0]%=mod;
			
			
			int mn=min(mx,j+a[i+1]);
			dp[i+1][mn][1]+=(dp[i][j][1]+dp[i][j][0])%mod;
			dp[i+1][mn][1]%=mod;
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=mx;j>=0;j--){
			f[i][j]=((dp[i][j][1]+dp[i][j][0])%mod+f[i][j+1])%mod;
//			f[i][j]=(dp[i][j][1]+f[i][j+1])%mod;
		}
	}
//	for(int i=0;i<=mx;i++){
//		for(int j=1;j<=n;j++){
//			f[j][i]=(f[j-1][i]+g[j][i])%mod;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=mx;j++){
//			for(int k=1;k<i;k++){
//				if()
//			}
//		}
//	}
//	for(int j=1;j<=mx;j++){
//		for(int i=1;i<=n;i++){
//			g[i][j]=(g[i-1][j]+dp[i][j][1])%mod;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=mx;j>=0;j--){
//			f[i][j]=(f[i][j+1]+g[i][j]);
//		}
//	}
	long long ans=0,j=2;
	for(int i=3;i<=n;i=j+1){
		j++;
		while(a[j+1]==a[i]){
			j++;
		}
		int tp=2*a[i]+1;
		for(int k=1;k<=mp[a[i]];k++){
			int t=max(0,tp-k*a[i]);
			ans=(ans+f[i-1][t]*C(mp[a[i]],k)%mod)%mod;
//			ans=(ans+f[i][max(0,tp-(k-1)*a[i])]*C(mp[a[i]],k)%mod)%mod;
		}
//		if(i==3) cout<<"###  "<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
} 
