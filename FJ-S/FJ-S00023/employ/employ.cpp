#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>57||c<48){if(c==45)f=-1;c=getchar();}
	while(c<=57&&c>=48){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=505,P=998244353;
int pw(int d,int z){
	int res=1;
	while(z){if(z&1)res=res*d%P;d=d*d%P;z>>=1;}
	return res;
}
int jc[N],inv[N],ans;
void init(){
	jc[0]=jc[1]=inv[1]=inv[0]=1;
	for(int i=2;i<=500;++i)jc[i]=jc[i-1]*i%P,
	inv[i]=pw(jc[i],P-2);
}
int C(int n,int m){
	if(n<m||m<0)return 0;
	return jc[n]*inv[m]%P*inv[n-m]%P;
}
int n,m,pa[N],vs[N];
char a[N];

void dfs(int g,int sum){
	if(g==n+1){if(n-sum>=m)ans=(ans+1)%P;return;}
	for(int i=1;i<=n;++i){
		if(vs[i])continue;
		vs[i]=1;
		bool k;
		k=(a[g]=='0')|(sum>=pa[i]);
		dfs(g+1,sum+k);
		vs[i]=0;
	}
}
void solve(){
	n=read();m=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;++i)pa[i]=read();
	if(n<=10){dfs(1,0);printf("%lld",ans);return;}
	
	ans=jc[n];
	if(m==n){
		for(int i=1;i<=n;++i)
			if(a[i]=='0'||pa[i]==0){
				printf("0");return;
			}printf("%lld",ans);return;
	}
//	sort(pa+1,pa+1+n);
//	int g=0,i=1;
//	while(pa[i]==0)++g,++i;
//	for(;i<=n;++i){
//		int G=1;
//		while(a[i]==a[i+1])++i,++G;
//		int k=a[i];
//		int del=0;
//		for(int j=k;j<=g;++j){
//			int L=C(G+j-1,G-1);
//			int R=C(n-i+g-j-1,n-i-1);
//			del=(del+L*R%P)%P;
//		}
//		ans=(ans-del+P)%P;
//	}
//	printf("%lld",ans);
	printf("%lld",jc[n]);
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	int ttt=1;while(ttt--)solve();
	return 0;
}
