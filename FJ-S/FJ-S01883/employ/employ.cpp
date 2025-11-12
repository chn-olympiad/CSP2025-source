#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0; char ch; bool f=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') f=1;
	else x=(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
const int N=505,mod=998244353;
int n,m;
char s[N];
int c[N],a[N];
namespace solve1{
	int p[15];
	void solve(){
		for(int i=1;i<=n;i++) p[i]=i;
		int ans=0;
		do{
			int d=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0') d++;
				else if(d>=a[p[i]]) d++;
				else ;
			}
			if(d<=n-m) ans++;
		}while(next_permutation(p+1,p+1+n));
		printf("%d\n",(ans%mod+mod)%mod);
	}
}
ll f[2][N][N],g[N][N],C[N][N],A[N][N];
ll jc[2][N];
int s1[N];
void re(){
	jc[0][0]=jc[0][1]=jc[1][0]=jc[1][1]=1;
	for(int i=2;i<N;i++){
		jc[0][i]=jc[0][i-1]*i%mod;
		jc[1][i]=(mod-mod/i)*jc[1][mod%i]%mod;
	}
	for(int i=2;i<N;i++){
		jc[1][i]=jc[1][i-1]*jc[1][i]%mod;
	}
	for(int i=0;i<N;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
		for(int j=0;j<=i;j++){
			A[i][j]=C[i][j]*jc[0][j]%mod;
		}
	}
}
void cl(int bz){
	for(int j=0;j<=n;j++){
		for(int k=0;k<=n;k++) f[bz][j][k]=0;
	}
}
inline void ad(ll &x,ll y){
	x=(x+y)%mod;
}
int main(){
//	system("fc employ5.ans employ.out"); return 0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	re();
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		a[i]=read();
		c[a[i]]++;
	}
//	if(n<=10){
//		solve1::solve(); return 0;
//	}
	for(int i=0;i<=n;i++){
		s1[i]=c[i];
		if(i>0) s1[i]+=s1[i-1];
	}
	int bz=0; cl(bz); f[bz][0][0]=1;
	for(int i=1;i<=n;i++){
		bz^=1; cl(bz); 
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(f[bz^1][j][k]){
					if(s[i]=='0'){
						//<=j
						for(int t=0;t<=c[j+1]&&k+1+t<=i;t++){
							ad(f[bz][j+1][k+1+t],f[bz^1][j][k]*A[c[j+1]][t]%mod*(s1[j]-k)%mod*C[i-1-k][t]%mod);
						}
						//=j+1
						for(int t=0;t<c[j+1]&&k+1+t<=i;t++){
							ad(f[bz][j+1][k+1+t],f[bz^1][j][k]*A[c[j+1]][t]%mod*C[i-1-k][t]%mod*(c[j+1]-t)%mod);
						}
						//>j+1
						for(int t=0;t<=c[j+1]&&k+t<i;t++){
							ad(f[bz][j+1][k+t],f[bz^1][j][k]*A[c[j+1]][t]%mod*C[i-1-k][t]%mod);
						}
					}
					else{
						// <=j
						for(int t=0;t<=c[j+1]&&k+1+t<=i;t++) ad(f[bz][j+1][k+1+t],f[bz^1][j][k]*A[c[j+1]][t]%mod*(s1[j]-k)%mod*C[i-1-k][t]%mod);
						// >=j+1
						ad(f[bz][j][k],f[bz^1][j][k]);
					}
				}
			}
		}
//		cerr<<i<<":-----------------------\n";
//		for(int j=0;j<=n;j++){
//			for(int k=0;k<=n;k++){
//				if(f[bz][j][k]) cerr<<j<<","<<k<<": "<<f[bz][j][k]<<"\n";
//			}
//		}
	}
	ll ans=0;
	for(int j=0;j<=n;j++){
		for(int k=0;k<=n;k++){
			if(j<=n-m&&n-s1[j]-(n-k)>=0){
//				cerr<<j<<","<<k<<": "<<f[bz][j][k]<<"!!"<<n-s1[j]-(n-k)<<"!!\n";
				ad(ans,f[bz][j][k]*jc[0][n-s1[j]]);
			}
		}
	}
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}
/*
s1[i]=\sum [c[j]<=i] 
f[i][j][k]表示1~i,当前d[i]==j,并且有k个<=j的c填了 方案数
1.s[i]==0:(无)
f[i-1][j][k]*(s1[j]-k)->f[i][j+1][k+1]
f[i-1][j][k]*c[j+1]->f[i][j+1][k+1]
f[i-1][j][k]*(n-s1[j+1]-(>j并且已填: i-1-k))->f[i][j+1][k]
2.s[i]==1:

1.T[i]==0:(c[p]<=j)
f[i-1][j][k]*(s1[j]-k)->f[i][j+1][k+1]
2.T[i]==1: 
1.(c[p]<=j) *f[i-1][j][k]*(s1[j]-k)->f[i][j][k+1]
2.无：f[i-1][j][k]*()
还可能选出若干个c[x]==j+1的x，放入还没填的位置上 
f[i-1][j][k]*C[c[x]][t]->f[i][j]
*/
