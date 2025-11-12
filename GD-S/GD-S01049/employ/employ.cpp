#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define MP make_pair
//#define int long long
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define ep emplace
#define eb emplace_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
bool Mbe;

template<typename T>void chkmin(T&x,T y){if(y<x)x=y;}
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')f^=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')s=s*10+c-'0',c=getchar();
	return f?s:-s;
}
const int N=505,mod=998244353;
int fpow(int x,int k=mod-2){
	int res=1;
	for(;k;k>>=1){
		if(k&1)res=(ll)res*x%mod;
		x=(ll)x*x%mod;
	}
	return res;
}
int fplus(int x,int y){return x+y>=mod?x+y-mod:x+y;}
void Fplus(int&x,int y){x=fplus(x,y);}
int fminus(int x,int y){return x<y?x+mod-y:x-y;}
void Fminus(int&x,int y){x=fminus(x,y);} 
int n,m,a[N],s[N],ans;
int f2[1<<18][19],bpp[1<<18];
void Sub1(){
	f2[0][0]=1;
	rep(S,1,(1<<n)-1)bpp[S]=bpp[S>>1]+(S&1);
	rep(S,0,(1<<n)-1)rep(i,0,n-1)if(f2[S][i])rep(j,0,n-1)if(!(S>>j&1)){
		if(i>=a[j+1]||!s[bpp[S]+1])Fplus(f2[S|1<<j][i+1],f2[S][i]);
		else Fplus(f2[S|1<<j][i],f2[S][i]); 
	}
	rep(i,m,n)Fplus(ans,f2[(1<<n)-1][n-i]);
	printf("%d\n",ans);
}
int b[N],f[N][N][N],fac[N],ifac[N];
int A(int x,int y){return (ll)fac[x]*ifac[x-y]%mod;}
int C(int x,int y){return x<y?0:(ll)fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
void Sub3(){
	int ans=fac[n];
	rep(i,1,n)if(!s[i]||!a[i])ans=0;
	printf("%d\n",ans);
	exit(0);
}
bool Med;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fprintf(stderr,"%.3lfMb\n",(&Mbe-&Med)/1024./1024.);
	n=read(),m=read();
	fac[0]=1;
	rep(i,1,n)fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=fpow(fac[n]);
	per(i,n,1)ifac[i-1]=(ll)ifac[i]*i%mod;
	rep(i,1,n)scanf("%1d",&s[i]);
	rep(i,1,n)a[i]=read();
	rep(i,1,n)b[a[i]]++;
	if(n<=18)Sub1();
	else Sub3();
	return 0;
}

