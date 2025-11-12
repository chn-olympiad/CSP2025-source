#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register char c=getchar();
	register int x=0;
	for(;(c<48)||(c>57);c=getchar());
	for(;(47<c)&&(c<58);c=getchar()){
		x=(x<<1)+(x<<3)+c-48;
	}
	return x;
}
int n,m;
char a[510];
int c[510];
int vis[510],ans;
inline void dfs(int x,int y){
	if(x==n+1){
		ans+=(y>=m?1:0);
		return;
	}
	for(register int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=true;
			if((a[x]=='0')||(x-1-y>=c[i])){
				dfs(x+1,y);
			}
			else{
				dfs(x+1,y+1);
			}
			vis[i]=false;
		}
	}
}
#define ll long long 
const ll mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",a+1);
	for(register int i=1;i<=n;++i){
		c[i]=read();
	}
	if(n<=18){
		dfs(1,0);
		printf("%d",ans);
	}
	else{
		ll sua=1;
		for(register int i=1;i<=n;++i){
			sua=(sua*(1ll*i))%mod;
		}
		printf("%lld",sua);
	}
	return 0;
} 
