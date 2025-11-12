#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],cnt[N],f[N][N],g[N][N],A[N][N],ans,C[N][N],suf[N];
string s;
inline void Mod(int &x){x>=mod?x-=mod:0;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;++i) cin>>c[i],++cnt[c[i]];
	for(int i=A[0][0]=C[0][0]=1;i<=n;++i){
		for(int j=A[i][0]=1;j<=i;++j) A[i][j]=1ll*A[i][j-1]*(i-j+1)%mod;
		for(int j=C[i][0]=1;j<=i;++j) Mod(C[i][j]=C[i-1][j]+C[i-1][j-1]);
	}
	for(int i=n;~i;--i) suf[i]=suf[i+1]+cnt[i];
	f[0][0]=1;
	for(int i=0,sum=0;i<=n-m;++i){
		sum+=cnt[i];
		for(int j=0;j<=n;++j)
		for(int k=1;k<=j;++k) if(f[j][k])
		for(int c=1;c<=k&&c<=cnt[i];++c) Mod(f[j][k-c]+=1ll*f[j][k]*A[cnt[i]][c]%mod*C[k][c]%mod);
		for(int j=0;j<n;++j)
		for(int k=0;k<=j;++k)if(f[j][k]){
			if(s[j+1]=='0'){
				Mod(g[j+1][k+1]+=f[j][k]);//no1
				Mod(g[j+1][k]+=1ll*f[j][k]*max(0,sum-(j-k))%mod);//no2
			}else{
				Mod(g[j+1][k]+=1ll*f[j][k]*max(0,sum-(j-k))%mod);//no
				Mod(f[j+1][k+1]+=f[j][k]);//yes
			}
		}
		for(int k=0;k<=n;++k) Mod(ans+=1ll*f[n][k]*A[suf[i+1]][k]%mod);
		for(int j=0;j<=n;++j)
		for(int k=0;k<=j;++k) f[j][k]=g[j][k],g[j][k]=0;
	}
	cout<<ans;
	return 0;
}

