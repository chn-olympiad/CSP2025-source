#include <bits/stdc++.h>
#define pa pair <int,int>
#define int long long
#define y second
#define x first
using namespace std;
const int N=5e3+10,M=998244353;

inline int read(){
	int ans=0;bool f=0;char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return (f?-ans:ans);
}

inline void write(int x,string s=""){
	if(x<0) x=-x,putchar('-');
	static char a[50],k=0;
	do{a[short(++k)]=x%10,x/=10;}while(x);
	while(k) putchar(a[short(k--)]|48);
	if(s=="\n") putchar('\n'); else if(s==" ") putchar(' ');
}

int n,a[N],f[N],p[N][N],g[N],q=1,ans,fp[N<<1],c[N][N];

void ini(){
	f[1]=1;
	for(int i=2;i<=5010;++i) f[M]=(M-M/i)*f[M%i]%M;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=5002;++i) c[0][i]=c[i][i]=1;
	for(int i=1;i<=5002;++i){
		for(int j=i+1;j<=5002;++j) c[i][j]=(c[i-1][j-1]%M+c[i][j-1]%M)%M;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j) g[i]=(g[i]+c[j][i])%M;
	}
	for(int i=1;i<=n;++i) a[i]=read();
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=5000;++j){
			p[i][j]=p[i-1][j];
			if(a[i]>j) p[i][j]=(p[i][j]%M+g[i-1]%M+1%M)%M;
			else if(a[i]==j) p[i][j]=(p[i][j]%M+g[i-1]%M)%M;
			else p[i][j]=(p[i][j]%M+p[i-1][j-a[i]]%M)%M;
		}
	}
	for(int i=3;i<=n;++i) ans=(ans%M+p[i-1][a[i]]%M)%M;
	write(ans,"\n");
	return 0;
}
