#include<bits/stdc++.h>
#define ll long long
#define gc() getchar()
#define pc(a) putchar(a)
#define f(i,a,b,n) for(int i=a;i<=b;i+=n)
#define TT template<typename T> 
using namespace std;
TT T in(){
	T c=0,f=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		c=(c<<3)+(c<<1)+(ch^48);
		ch=gc(); 
	}
	return c*f;
}
TT void out(T x){
	if(x<0) pc('-'),x=-x;
	if(x<10) pc((int)x^48);
	else out<T>((int)x/10),pc((int)(x%10)^48);
}
int n,m,s[505],c[505];
ll ans,mod=998244353;
bool vis[505];
ll powe(int k){
	ll an=1;
	while(k) an=(an*(k--))%mod;
	return an;
}
void dfs(int num,int now){
	if(now==m){
		ans=(ans+powe(n-num+1))%mod;
		return ;
	}
	if(n-num+1<m-now) return ;
	f(i,1,n,1) if(!vis[i]){
		vis[i]=true;
		if(!s[num]||num-now-1>=c[i]) dfs(num+1,now);
		else dfs(num+1,now+1);
		vis[i]=false;
	} 
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in<int>(),m=in<int>();
	f(i,1,n,1) if(gc()=='1') s[i]=1;
	f(i,1,n,1) c[i]=in<int>();
	dfs(1,0);
	out<ll>(ans);
	return 0;
}
