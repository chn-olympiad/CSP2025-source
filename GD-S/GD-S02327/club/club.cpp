#include<bits/stdc++.h>
using namespace std;
#define is(x) isdigit(x)
#define g getchar()
typedef unsigned int ll;
inline void r(ll &x){
	x=0;char c=g;ll f=1;
	while(!is(c)){
		if(c=='-'){
			f*=-1;
		}
		c=g;
	}
	while(is(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=g;
	}
	x*=f;
	return ;
}
ll t,n,ans,a[10010],b[10010],c[10010];
void dfs(int x,ll sum,int ca,int cb,int cc){
	if(ca>n/2||cb>n/2||cc>n/2){
		return ;
	}	
	if(n==x){
		ans=max(sum,ans);
		return ;
	}
	if(a[x+1]) dfs(x+1,sum+a[x+1],ca+1,cb,cc);
	if(b[x+1]) dfs(x+1,sum+b[x+1],ca,cb+1,cc);
	if(c[x+1]) dfs(x+1,sum+c[x+1],ca,cb,cc+1);
}
const ll N=2e4;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	r(t);
	while(t--){
		ans=0;
		r(n);
		for(int i=1;i<=n;i++){
			r(a[i]);r(b[i]);r(c[i]);
		}
		dfs(0,0,0,0,0);
		printf("%lld\n",ans);
	}	
	return 0;
}
