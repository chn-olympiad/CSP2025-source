#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=f;
	return;
}
template<typename T>
inline void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=5e2+5;
const int S=(1<<18)+5;
const int mod=998244353;
int n,m,c[N],fac[N],ans,f[S][N];
bool tag[N];
char s[N];
void dfs(int u,int cnt,int p){
	if(p>=m) return (void)(ans=(ans+fac[n-u+1])%mod);
	if(u>n) return;
//	cout<<u<<' '<<cnt<<'\n';
	for(int i=1;i<=n;i++){
		if(tag[i]) continue;
		tag[i]=true;
		if(cnt>=c[i]||s[u]=='0') dfs(u+1,cnt+1,p);
		else dfs(u+1,cnt,p+1);
		tag[i]=false;
	}
}
void solve(){
	read(n);read(m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) read(c[i]);
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	if(n<=18){
		int S=(1<<n)-1;
		f[0][0]=1;
		for(int i=0;i<S;i++){
			int cnt=0;
			for(int j=1;j<=n;j++)
				if(i&(1<<j-1)) cnt++;
			for(int j=1;j<=n;j++){
				if(i&(1<<j-1)) continue;
				int suc=(i^(1<<j-1));
				for(int k=0;k<=n;k++){
					int md=(k>=c[j]||s[cnt+1]=='0');
					f[suc][k+md]=(f[suc][k+md]+f[i][k])%mod;
//					cout<<suc<<' '<<k+md<<' '<<f[i][k]<<'\n';
				}
			}
		}
		for(int i=m;i<=n;i++) ans=(ans+f[S][n-i])%mod;
		write(ans);
		putchar('\n');
	}
	else{
		dfs(1,0,0);
		write(ans);
		putchar('\n');
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int c=1,T=1;
	while(T--) solve();
	return 0;
}
