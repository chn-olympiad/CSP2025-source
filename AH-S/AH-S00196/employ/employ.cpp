#include<bits/stdc++.h>
using namespace std;
typedef long long ll1;
const ll1 mod=998244353;
const int N=505;
ll1 fac[N],ifac[N];
ll1 ksm(ll1 x,ll1 y){ll1 res=1;for(;y;y>>=1,x=x*x%mod)if(y&1)res=res*x%mod;return res;}
void add(ll1 &x,ll1 y){x=x+y<mod?x+y:x+y-mod;}
int n,m;
char s[N];
int cnt[N],sm[N];
ll1 f[N][N][N];
//有 i 个没被录取，且 cnt\in[1,i] 的填了 j 个，其余填了 k 个。
//注意不算 k 的贡献！
ll1 Ans=0;
ll1 C(ll1 x,ll1 y){
	if(x<0||y<0||x<y)return 0;
	return fac[x]*ifac[x-y]%mod*ifac[y]%mod;
}
ll1 A(ll1 x,ll1 y){
	if(x<0||y<0||x<y)return 0;
	return fac[x]*ifac[x-y]%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=500;
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	ifac[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),cnt[x]++;
	sm[0]=cnt[0];
	for(int i=1,x;i<=n;i++)sm[i]=sm[i-1]+cnt[i];
	memset(f,0,sizeof f);
	f[0][0][0]=1;
	for(int i=0;i<=n-m;i++)
	for(int j=0;j<=sm[i];j++)
	for(int k=0;k<=n-sm[i];k++){
		int nw=j+k+1;
		if(s[nw]=='0'){//不可录取。
			if(k<n-sm[i]){//你很强，但是你完了
				//i+1,枚举 k+1 分布在 i+1 的个数
				//->f[i+1][j+?][k+1-?]
				for(int c=0;c<=cnt[i+1]&&c<=k+1;c++)
					add(f[i+1][j+c][k+1-c],f[i][j][k]*A(cnt[i+1],c)%mod*C(k+1,c)%mod);
			}
		}else{//可以录取。
			if(k<n-sm[i])add(f[i][j][k+1],f[i][j][k]);
		}
		if(j<sm[i]){
			//菜鸡！它一定退役！
			//i+1，枚举 k 分布在 i+1 的个数
			//->f[i+1][j+1+?][k-?]
			for(int c=0;c<=cnt[i+1]&&c<=k;c++)
				add(f[i+1][j+1+c][k-c],f[i][j][k]*(sm[i]-j)%mod*A(cnt[i+1],c)%mod*C(k,c)%mod);
		}
	}
	Ans=0;
	for(int i=0;i<=n-m;i++)add(Ans,f[i][sm[i]][n-sm[i]]*fac[n-sm[i]]%mod);
	printf("%lld\n",Ans);
	return 0;
}