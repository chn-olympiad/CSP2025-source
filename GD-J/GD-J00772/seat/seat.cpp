#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,x,s,u=1,v=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&a);
	for(int i=2;i<=n*m;i++){
		scanf("%lld",&x);
		if(x>a)s++;
	}
	while(s>0){
		if(u&1)v++;
		else v--;
		if(v>n){
			u++;
			v=n;
		}
		if(v<1){
			u++;
			v=1;
		}
		s--;
	}
	printf("%lld %lld",u,v);
	return 0;//zrt2
} 
