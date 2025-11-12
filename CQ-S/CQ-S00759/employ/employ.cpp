#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N];
string s;
namespace baoli{
	int f[1<<18][19];
	void main(){
		f[0][0]=1;
		for(int i=1;i<(1<<n);i++){
			int wz=__builtin_popcount(i);
			for(int j=0;j<=n-m;j++)
				for(int k=0;k<n;k++)
					if(i>>k&1){
						int x=j>c[k+1]||(s[wz]=='0');
						if((j!=c[k+1]||x)&&j>=x)f[i][j]=(f[i][j]+f[i^(1<<k)][j-x])%mod;
					}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)ans=(ans+f[(1<<n)-1][i])%mod;
		cout<<ans;
	}
}
namespace spA{
	int sum[N],f[N][N],C[N][N],qz[N];
	void main(){
		C[0][0]=qz[0]=1;
		for(int i=1;i<=n;i++){
			qz[i]=1ll*qz[i-1]*i%mod; 
			for(int j=0;j<=i;j++)C[i][j]=(C[i-1][j]+(j?C[i-1][j-1]:0))%mod;
		}
		for(int i=1;i<=n;i++)sum[c[i]]++;
		for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
		f[0][sum[0]]=1;
		for(int i=0;i<n-m;i++)
			for(int j=1;j<=sum[i];j++){
				if(!f[i][j])continue;
				int zo=sum[i+1]-sum[i];
				for(int k=0;k<=zo;k++){
					f[i+1][j+k-1]=(f[i+1][j+k-1]+1ll*f[i][j]*C[sum[i+1]-j-k][zo-k]%mod*C[zo][k]%mod*qz[zo-k]%mod*j%mod)%mod;
				}
			}
		int ans=0;
		for(int i=0;i<=n-m;i++)ans=(ans+1ll*f[i][0]*C[n][i]%mod*qz[n-sum[i]]%mod)%mod;
		cout<<ans;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

//	freopen("employ3.in","r",stdin);
//	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18)baoli::main();
	else{
		bool fg=1;
		for(int i=1;i<=n;i++)
			if(s[i]=='0')fg=0;
		if(fg)spA::main();
		else cout<<0;
	}
	return 0;
}//44pts跑路，希望T3能拿许多分 
