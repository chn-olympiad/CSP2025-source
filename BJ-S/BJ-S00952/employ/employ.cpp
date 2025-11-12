#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define REPG(i,g,x) for(int i=g.head[x];~i;i=g.edge[i].nxt)
#define LL long long

template<class T>
inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
template<class T>
inline void write(T x){
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}

const int N=505;
const int mod=998244353;
inline int pls(int a,int b){
	return (a+b>=mod?a+b-mod:a+b);
}
inline void add(int &x,int y){
	x=pls(x,y);
}
inline int mns(int a,int b){
	return (a-b<0?a-b+mod:a-b);
}
inline int mul(int a,int b){
	return (LL)a*b%mod;
}
int n,m;
string s;
int c[N];
namespace sub1{
	int p[15];
	inline void solve(){
		iota(p+1,p+n+1,1);
		int ans=0;
		do{
			int cnt=0;
			rep(i,1,n){
				if(s[i]=='0') cnt++;
				else{
					if(c[p[i]]<=cnt) cnt++;
				}
			}
			if(cnt<=n-m) ans++;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
	}
}

namespace sub3{
	const int CF=18,MF=(1<<CF)+5;
	int f[2][20][MF];
	inline void solve(){
		int U=(1<<n)-1;
		f[0][0][U]=1;
		rep(i,0,n-1){
			int p=i&1,q=p^1;
			rep(j,0,i) rep(S,0,U){
				if(!f[p][j][S]) continue;
				rep(u,1,n){
					if(!((S>>(u-1))&1)) continue;
					add(f[q][j+(c[u]>i-j && s[i+1]=='1')][S^(1<<(u-1))],f[p][j][S]);
				}
			}
			// rep(j,0,i+1) rep(S,0,U) 
			// 	printf("f[%d][%d][%d]=%d\n",i+1,j,S,f[q][j][S]);
			memset(f[p],0,sizeof(f[p]));
		}
		int ans=0;
		rep(j,m,n) ans=pls(ans,f[n&1][j][0]);
		printf("%d\n",ans);
	}
}

namespace sub15{
	inline void solve(){
		rep(i,1,n) if(s[i]=='0' || c[i]==0) {
			printf("0\n");
			return;
		}
		int ans=1;
		rep(i,1,n) ans=mul(ans,i);
		printf("%d\n",ans);
	}
}

namespace sub12{
	int cnt[N];
	inline void solve(){
		int all=1;
		rep(i,1,n) all=mul(all,i);
		rep(i,1,n) cnt[c[i]]++;
		rep(i,1,n) cnt[i]+=cnt[i-1];
		int res=1,ct0=0;
		rep(i,1,n) {
			if(s[i]=='0') ct0++;
			else{
				res=mul(res,max(0,cnt[i-1]-(i-1-ct0)));
			}
		}
		rep(i,1,ct0) res=mul(res,i);
		printf("%d\n",mns(all,res));
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	cin>>s;s=" "+s;
	rep(i,1,n) read(c[i]);
	if(n<=10) sub1::solve(),exit(0);
	if(n<=18) sub3::solve(),exit(0);
	if(m==n) sub15::solve(),exit(0);
	if(m==1) sub12::solve(),exit(0);
	return 0;
}