#include<bits/stdc++.h>
using namespace std;
#define g getchar()
#define is(x) isdigit(x)
typedef long long ll;
inline void r(unsigned int &x){
	x=0;char c=g;ll f=1;
	while(!is(c)){
		c=g;
	}
	while(is(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=g;
	} 
	x*=f;
	return ;
}
const ll N=1e5,Mod=998244353;
unsigned int n,ans,num[N];
void dfs(ll l,ll x){
	if(l>2*num[x]){
		ans++;
		ans%=Mod;
	}
	if(x==n){
		return ;
	}
	for(int i=x+1;i<=n;i++){
		dfs(l+num[i],i);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	r(n);
	for(int i=1;i<=n;i++){
		r(num[i]); 
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
