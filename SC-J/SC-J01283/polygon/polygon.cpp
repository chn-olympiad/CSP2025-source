#include<bits/stdc++.h>
using namespace std;
#ifdef __unix
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
inline int read(){return 0;}
template<typename A,typename ...B>
int read(A &x,B&...y){
	x=0;int f=1,c=gc();
	for(;!isdigit(c);c=gc()){
		if(!(~c)) return 0;
		if(c=='-') f=-1;
	}
	for(;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^48);
	return x*=f,read(y...)+1;
}
inline int write(){return 0;}
inline void Write(char c){pc(c);}
inline void Write(const char *a){
	for(int i=0;a[i];++i) pc(a[i]);
}
template<typename T>
void Write(T x){
	if(x<0) pc('-'),x=-x;
	if(x<10) return pc(x^48),void(0);
	Write(x/10),pc((x%10)^48);
}
template<typename A,typename ...B>
int write(A x,B...y){
	Write(x);
	return write(y...)+1;
}
#define int long long
#define N 5010
//#define NoFreopen
//#define DEBUG
constexpr int mod(998244353);
int n,a[N],f[N],maxn,ans;
#ifdef DEBUG
int pos[N];
#endif
inline void mul(int &a,int b){a=(a*b)%mod;}
inline void add(int &a,int b){a=(a+b)%mod;}
inline int Pow(int a,int b){
	int ans(1);
	while(b){
		if(b&1) mul(ans,a);
		mul(a,a);
		b>>=1;
	}
	return ans;
}
inline int C(int n,int m){
	return (f[n]*Pow(f[n-m]*f[m]%mod,mod-2))%mod;
	/*(f[n]/(f[n-m]*f[m]))%mod
	 =(f[n]*(f[n-m]*f[m])^p-2)%mod
	*/
}
inline void gmax(int &a,int b){if(a<b) a=b;}
void dfs(int sum,int x=1,int last=0,int tot=0,int maxn=0){
	if(x==sum+1)
		return void(add(ans,tot>(maxn<<1)));
	for(int i=last+1;i<=n-sum+x;++i){
		#ifdef DEBUG
		pos[x]=i;
		#endif
		dfs(sum,x+1,i,tot+a[i],max(maxn,a[i]));
	}
}
signed main(){
	#ifndef NoFreopen
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	#endif
	read(n);
	f[0]=1;
	for(int i=1;i<=n;++i){
		read(a[i]);
		f[i]=(f[i-1]*i)%mod;
		gmax(maxn,a[i]);
	}
	if(maxn==1){
		for(int i=3;i<=n;++i){
			add(ans,C(n,i));
		}
		write(ans);
		return 0;
	}
	for(int i=3;i<=n;++i){
		dfs(i);
	}
	write(ans);
	return 0;
}
