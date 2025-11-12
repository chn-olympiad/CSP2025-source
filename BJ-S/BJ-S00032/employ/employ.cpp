#include<bits/stdc++.h>
#define int long long
using namespace std;
using Pair=pair<int,int>;
constexpr int N=100+5,M=500+5,MAX=0x3fff'ffff'ffff'ffff,P=998244353;
namespace{
	int Pow(int a,int k){
		if(a<0||a>=P) a=(a%P+P)%P;
		if(k<0||k>=P-1) k=(k%(P-1)+(P-1))%(P-1);
		int ans=1;
		while(k){
			if(k&1) (ans*=a)%=P;
			(a*=a)%=P; k>>=1;
		}
		return ans;
	}
	int Inv(int a){return Pow(a,P-2);}
	int Fac[M],IFac[M];
	int A(int n,int m){
		if(n<0||m<0||n-m<0) return 0;
		return Fac[n]*IFac[n-m]%P;
	}
	int C(int n,int m){
		if(n<0||m<0||n-m<0) return 0;
		return Fac[n]*IFac[m]%P*IFac[n-m]%P;
	}
	void Init(int n){
		Fac[0]=1; for(int i=1;i<=n;i++) Fac[i]=Fac[i-1]*i%P;
		IFac[n]=Inv(Fac[n]); for(int i=n-1;i>=0;i--) IFac[i]=IFac[i+1]*(i+1)%P;
	}
}
int n,m,c[M],Sc[M];
bool s[M];
namespace Sol1{
	int Solve(){
		bool flag=(c[0]==0);
		for(int i=1;i<=n;i++) if(s[i]==0) flag=0;
		return (flag?Fac[n]:0);
	}
}
int f[N][N][N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m; Init(n);
	int cnt1=0;
	for(int i=1;i<=n;i++){
		char x; cin>>x;
		s[i]=(x=='1'?1:0);
		cnt1+=(x=='1'?1:0);
	}
	for(int i=1;i<=n;i++){
		int x; cin>>x; c[x]++;
	}
	if(cnt1==n||m==n) cout<<Sol1::Solve()<<'\n';
	else{
		Sc[0]=c[0]; for(int i=1;i<=n;i++) Sc[i]=Sc[i-1]+c[i];
		f[0][0][0]=1;
		for(int i=1;i<=n;i++) for(int j=0;j<=i;j++) for(int k=0;k<=i;k++) if(s[i]==1){
			if(j!=0) (f[i][j][k]+=f[i-1][j-1][k])%=P;
			for(int x=0;x<k;x++){
				int coef=(i-j-1<0?0:max(0ll,Sc[i-j-1]-(k-x-1)));
				if(coef) (f[i][j][k]+=f[i-1][j][k-x-1]*C(c[i-j],x)%P*C(i-k+x,x)%P*Fac[x]%P*coef%P)%=P;
			}
		}else{
			for(int x=0;x<=k;x++){
				(f[i][j][k]+=f[i-1][j][k-x]*C(c[i-j],x)%P*C(i-k+x,x)%P*Fac[x]%P)%=P;
			}
			for(int x=0;x<k;x++){
				int coef=(i-j-1<0?0:max(0ll,Sc[i-j-1]-(k-x-1)));
				if(coef) (f[i][j][k]+=f[i-1][j][k-x-1]*C(c[i-j],x)%P*C(i-k+x,x)%P*Fac[x]%P*coef%P)%=P;
			}
		}
		int ans=0;
		for(int j=m;j<=n;j++) ans+=f[n][j][Sc[n-j]]*Fac[n-Sc[n-j]]%P,ans%=P;
		cout<<ans<<'\n';
	}
}