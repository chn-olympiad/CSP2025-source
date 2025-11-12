#include <bits/stdc++.h>
using namespace std;
long long a,n,x,ans=1,h,l,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&x);
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>x){
			ans++;
		}
	}
	if(ans%n==0){
		l=ans/n;
		if(l%2==1){
			h=m;
		}else{
			h=1;
		}
	}else{
		l=ans/n+1;
		if(l%2==1){
			h=ans%n;
		}else{
			h=m-ans%n;
		}
	}
	printf("%lld %lld",l,h);
	return 0;
} 
