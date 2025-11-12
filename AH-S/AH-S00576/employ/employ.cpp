#include<bits/stdc++.h>
using namespace std;
void in(int &x){
	char c=getchar();int f=1;
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')f=-f,c=getchar();
	x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
const int mod=998244353;
const int N=505;
const int M=500;
int n,m,a[N],pos[N],sum[N],al=0,fir=1,no,cnt;
char s[N];
long long dp[2][N][N];
//处理到第i位,总共钦定j位不合法,已经处理了k位不合法
long long f[N],g[N],ans;
long long fac[N],ifac[N];
long long ksm(long long p,int q){
	long long ans=1;
	while(q){
		if(q&1)ans=ans*p%mod;
		p=p*p%mod,q>>=1;
	}
	return ans;
}
long long get_c(int x,int y){
	if(x<y)return 0;
	return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=ifac[0]=1;
	for(int i=1;i<=M;i++)fac[i]=fac[i-1]*i%mod;
	ifac[M]=ksm(fac[M],mod-2);
	for(int i=M-1;i;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	in(n);in(m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(s[i]=='0');
		al+=s[i]=='1';
		in(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++){
		while(fir<=n&&a[fir]<=i)fir++;
		pos[i]=fir-1;
	}
	for(int i=0;i<=al;i++)dp[0][i][0]=1;
	no=1,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')continue;
		for(int j=0;j<=al;j++)for(int k=0;k<=al;k++)dp[no][j][k]=0;
		for(int j=0;j<=al;j++){
			for(int k=0;k<=j;k++){
				(dp[no][j][k]+=dp[no^1][j][k])%=mod;//未钦定
				if(k)(dp[no][j][k]+=dp[no^1][j][k-1]*max(0,pos[sum[i]+k-1]-(k-1)))%=mod;//钦定
			}
		}
		// for(int j=0;j<=al;j++){
		// 	for(int k=0;k<=al;k++){
		// 		printf("?%d %d %d %lld\n",i,j,k,dp[no][j][k]);
		// 	}
		// }
		cnt++;
		no^=1;
	}
	no^=1;
	for(int i=0;i<=al;i++)g[i]=dp[no][i][i]*fac[n-i]%mod;
	// for(int i=0;i<=al;i++)printf("!!%lld\n",g[i]);
	for(int i=0;i<=al;i++){
		for(int j=i;j<=al;j++){
			int ff=((j-i)&1)?-1:1;
			// f[i]=(f[i]+g[j]*get_c(j,i)*ff);
			f[i]=(f[i]+g[j]*ff+mod)%mod;
			// f[i]=(f[i]+g[j]*get_c(j,i)%mod*ff+mod)%mod;
		}
	}
	int lim=al-m;
	for(int i=0;i<=lim;i++)(ans=(ans+f[i]))%mod;
	cout<<ans;
	return 0;
}