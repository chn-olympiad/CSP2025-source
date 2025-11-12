#include<bits/stdc++.h>
using namespace std;
namespace zzy{
	const int maxn=500+10;
	const int mod=998244353;
	int n,m,ans;
	inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
	inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
	string s;
	int a[maxn],t[maxn],sum[maxn];
	int C[maxn][maxn],fac[maxn];
	int f[2][maxn][maxn],g[2][maxn][maxn]; //f:>= g:>
	void init(int n){
		for(int i=0;i<=n;i++){
			C[i][0]=C[i][i]=1;
			for(int j=1;j<=i-1;j++)C[i][j]=add(C[i-1][j-1],C[i-1][j]);
		}
		fac[0]=1;
		for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	} 
	int main(){
		cin>>n>>m;
		cin>>s;s=' '+s;
		for(int i=1;i<=n;i++)cin>>a[i],t[a[i]]++;
		sum[0]=t[0];
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+t[i];
		init(n);
		f[0][0][0]=g[0][0][0]=1;
		for(int i=1;i<=n;i++){
			int now=i&1,lst=now^1;
			for(int k=0;k<=i;k++)for(int x=0;x<=i;x++)f[now][k][x]=g[now][k][x]=0;
			for(int k=0;k<=i;k++){ 
				if(s[i]=='0'){
					if(!k)continue ;
					for(int x=0;x<=i;x++){
						if((sum[k-1]-(i-1-x))>0)f[now][k][x]=add(f[now][k][x],1ll*g[lst][k-1][x]*(sum[k-1]-(i-1-x))%mod);
						if(x)f[now][k][x]=add(f[now][k][x],g[lst][k-1][x-1]);
					}
				}else{
					for(int x=1;x<=i;x++)g[now][k][x]=add(g[now][k][x],g[lst][k][x-1]);
					if(!k)continue; 
					for(int x=0;x<=i;x++)if((sum[k-1]-(i-1-x))>0)f[now][k][x]=add(f[now][k][x],1ll*g[lst][k-1][x]*(sum[k-1]-(i-1-x))%mod);
				}
			}
			for(int k=0;k<=i;k++){
				for(int x=0;x<=i;x++){
					for(int p=x;p<=i&&p<=x+t[k];p++){
						g[now][k][x]=add(g[now][k][x],1ll*f[now][k][p]*C[t[k]][p-x]%mod*C[p][p-x]%mod*fac[p-x]%mod);
					}
				}
			}
		}
		for(int k=0;k<=n;k++){
			int x=0;
			int t=n-sum[k];
			for(int p=x+1;p<=n&&p<=x+t;p++)g[n&1][k][x]=add(g[n&1][k][x],1ll*g[n&1][k][p]*C[t][p-x]%mod*C[p][p-x]%mod*fac[p-x]%mod);
		}
		for(int i=0;i<=n-m;i++)ans=add(ans,g[n&1][i][0]);
		cout<<ans<<'\n';
		
		return 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	zzy::main();
	return 0;
}
//18:00 AK!
//5MB 
/*
张真源，严浩翔，刘耀文，贺俊霖 
luguanshijiandaole 
*/
