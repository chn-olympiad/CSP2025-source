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
ll n,m;
pair<ll,ll>num[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	r(n);r(m);
	for(int i=1;i<=n*m;i++){
		r(num[i].first);num[i].second=i;
	}
	sort(num+1,num+n*m+1);
	ll cnt=n*m;
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				if(num[cnt--].second==1){
					cout<<j<<" "<<i;
					return 0;
				}	
			}
		}
		else{
			for(int i=n;i>=1;i--){
				if(num[cnt--].second==1){
					cout<<j<<" "<<i;
					return 0;
				}	
			}
		}
	}
}

