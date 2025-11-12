#include<bits/stdc++.h>
using namespace std;
namespace ld{
	const int N=505;
	const int mod=998244353;
	int n,m,tong[N],sum[N];
	string s;
	int fac[N],C[N][N],f[2][N][N];
	int main(){
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		cin>>n>>m>>s;s=" "+s;
		C[0][0]=fac[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=1ll*fac[i-1]*i%mod,C[i][0]=1;
			for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}	
		for(int i=1,x;i<=n;i++)cin>>x,++tong[x];
		sum[0]=tong[0];
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+tong[i];
		int cnt=0;
		f[0][0][0]=1;
		for(int i=1;i<=n;i++){
			memset(f[i&1],0,sizeof(f[i&1]));
			if(s[i]=='0'){
				for(int j=cnt;j<=min(i,n-m);j++)
					for(int k=0;k<=i;k++){
						if(f[i-1&1][j][k]){
							for(int t=0;t<=k;t++)f[i&1][j+1][k-t]=(f[i&1][j+1][k-t]+1ll*f[i-1&1][j][k]*C[k][t]%mod*C[tong[j+1]][t]%mod*fac[t])%mod;						
						}
					}
					
				++cnt;
			}else {
				for(int j=cnt;j<=min(i,n-m);j++)
					for(int k=0;k<=i;k++){
						if(k)f[i&1][j][k]=(f[i&1][j][k]+f[i-1&1][j][k-1])%mod;		
						if(f[i-1&1][j][k]){
							for(int t=0;t<=k;t++){
								int ct=sum[j]-(i-1-cnt-k);
								if(ct>=1)f[i&1][j+1][k-t]=(f[i&1][j+1][k-t]+1ll*f[i-1&1][j][k]*C[k][t]%mod*C[tong[j+1]][t]%mod*fac[t]%mod*ct)%mod;
							}							
						}								
					}			
			}
		}
		int ans=0;
		for(int j=cnt;j<=n-m;j++){
			for(int k=0;k<=n;k++){
				ans=(ans+1ll*f[n&1][j][k]*C[sum[n]-sum[j]][k]%mod*fac[k]%mod)%mod;
			}
		}
		for(int i=1;i<=cnt;i++)ans=1ll*ans*i%mod;
		cout<<ans<<'\n';
		
		return 0;
	}
}
int main(){
	ld::main();
	return 0;
}
//¿Õ¼ä:mb/512mb
//Ê±¼ä:s/1s
