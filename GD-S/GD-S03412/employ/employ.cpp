#include <bits/stdc++.h>
using namespace std;

int n,m,s[507],c[507],su[507];
char ch;
int dp[2][507][507],CC[507][507],fac[507];
int h[507][507];
const int mod=998244353;
inline int C(int x,int y){
	if(x<0||y<0||x<y) return 0;
	return CC[x][y];
}
signed main(){
	freopen("employ.in" ,"r",stdin );
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>ch,s[i]=ch-'0';
	for(int i=1,x;i<=n;i++){
		cin>>x; 
		c[x]++;
	}
	fac[0]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=i-1;j<=n;j++){
			h[i][j]=1;
			for(int k=i;k<=j;k++){
				if(!s[k]) h[i][j]=0;
			}
		}
		fac[i]=1ll*fac[i-1]*i%mod;
	} 
	for(int i=0;i<=n+1;i++){
		CC[i][0]=1;
		for(int j=1;j<=i;j++){
			CC[i][j]=(CC[i-1][j]+CC[i-1][j-1])%mod;
		}
	}
	//for(int i=0;i<=n+1;i++) for(int j=0;j<=i;j++) CC[i][j]=1ll*CC[i][j]*fac[j]%mod;
	su[0]=c[0];
	for(int i=1;i<=n+1;i++) su[i]=su[i-1]+c[i];
	dp[0][0][0]=1;
	int ans=0;
	for(int i=1;i<=n-m+1;i++){
		int u=i&1,v=u^1;
		for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) dp[u][j][k]=0;
		for(int j=0;j<=su[i-1];j++){
			for(int k=0;k<=n-su[i-1];k++){
				int ss=dp[v][j][k];
				//cerr<<j<<" "<<k<<"??"<<endl;
				if(ss==0) continue;
				///cerr<<" "<<i<<" "<<j<<" "<<k<<" "<<ss<<endl; 
				for(int ii=0;k+ii<=n-su[i-1];ii++){
					if(!h[j+k+1][j+k+ii]) continue; 
					//cerr<<"???"<<endl;
					for(int k1=0;k1<=min(c[i],k);k1++){
						int k2=k-k1;
						for(int i1=0;i1+k1<=c[i]&&i1<=ii;i1++){
							int i2=ii-i1;
							if(k2+i2>n-su[i]) continue;
							//cerr<<i<<" !"<<j<<" "<<k1<<" "<<i1<<" "<<k2<<" "<<i2<<endl;
							int x=ss;
							x=1ll*x*C(c[i],k1)%mod*C(c[i]-k1,i1)%mod*C(i1+i2,i2)%mod*fac[k1]%mod*fac[i1]%mod*C(k,k1)%mod;
							if(j+k1+i1==su[i]&&k2+i2==n-su[i]){
								ans=(ans+1ll*x*fac[n-su[i]])%mod;
							}
							if(j+k+ii<n){
								if(j<su[i-1]) dp[u][j+k1+i1+1][k2+i2]=(dp[u][j+k1+i1+1][k2+i2]+1ll*x*(su[i-1]-j))%mod;
								if(s[j+k+ii+1]==0){
									if(k1+i1<c[i]) dp[u][j+k1+i1+1][k2+i2]=(dp[u][j+k1+i1+1][k2+i2]+1ll*x*(c[i]-k1-i1))%mod;
									if(k2+i2<n-su[i]) dp[u][j+k1+i1][k2+i2+1]=(dp[u][j+k1+i1][k2+i2+1]+x)%mod;
								}
							}
						}
					}
				}
			}
		}
		//cerr<<i<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 
