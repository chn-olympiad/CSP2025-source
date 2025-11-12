#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,mod=998244353;
ll read(){
	ll w=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return w*x;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar((x%10)+'0');
}
int n,m,p[N],c[N];
ll ans;
bool s[N],A=true,vis[N];
inline ll ksm(ll a,ll b){
	a%=mod;
	ll res=1;
	while(b){
		if(b&1) res=(a*res)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
bool check(){
	int res=0,out=0;
	for(int i=1;i<=n;i++){
		if(out>=c[p[i]]){
			out++;
			continue;
		}
		if(s[i]) res++;
		else out++;
	}
	return (res>=m);
}
void dfs(int stp){
	if(stp==(n+1)){
		if(check()) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			p[stp]=i;
			dfs(stp+1);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		if(ch=='1')s[i]=true;
		if(ch=='0')A=false;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	if(A){
		ans=1;
		for(int i=2;i<=n;i++){
			ans=(ans*i)%mod;
		}
	}
	else{
		dfs(1);
	}
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}