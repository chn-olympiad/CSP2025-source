#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=510,mod=998244353;
short c[maxn],n,m;
bool ok[maxn];
char s[maxn];
int jc[maxn],ny[maxn];
inline int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
inline int C(int x,int y){
	if(x<y) return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
inline int read(){
	int sum=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	} 
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum*f;
}
int cnt1,cnt2;
inline void ddsuba(){
	printf("%lld",jc[n]);
	exit(0);
}
inline void ddsubn(){
	if(n!=cnt2||cnt1!=n) printf("0");
	else printf("%d",jc[n]);
	exit(0); 
}
inline void ddsub1(){
	printf("%d",jc[n]);
	exit(0);
}
bool vis[maxn];
int ans;
inline void dfs(int x,int fail){
	if(n-fail<m) return;
	if(x==n+1){
		ans=(ans+1)%mod;
		return;
	}
	else if(fail-x-1>=m){
		ans=(ans+jc[n-x+1])%mod;
		return;
	}
	for(int i=1;i<=n;++i)
		if(vis[i]) continue;
		else{
			vis[i]=1;
			dfs(x+1,fail+(ok[x]==0||fail>=c[i]));
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	jc[0]=ny[0]=1;
	for(int i=1;i<=n;++i) jc[i]=1ll*jc[i-1]*i%mod,ny[i]=qpow(jc[i],mod-2);
	bool suba=1;
	scanf("%s",s);
	for(int i=1;i<=n;++i){
		ok[i]=s[i-1]-'0';
		if(!ok[i]) suba=0;
		else cnt1++;
	}
	for(int i=1;i<=n;++i) c[i]=read(),cnt2+=(c[i]!=0);
	if(m>cnt1||n-cnt2>m) printf("0"),exit(0);
	if(m==n) ddsubn();
	else{
		dfs(1,0);
		printf("%d",ans);
	} 
	return 0;
}