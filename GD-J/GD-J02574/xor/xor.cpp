#include<bits/stdc++.h>
using namespace std;
#define g getchar()
#define is(x) isdigit(x)
typedef long long ll;
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
const ll N=1e6;
ll n,k,num[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	r(n);r(k);ll l=1,ans=0;
	for(int i=1;i<=n;i++){
		r(num[i]);
		ll nw=0;
		for(int j=i;j>=l;j--){
			nw^=num[j];
			if(nw==k){
				ans++;
				l=i+1;
			}
		}
	}	
	printf("%lld",ans);
	return 0;
}
