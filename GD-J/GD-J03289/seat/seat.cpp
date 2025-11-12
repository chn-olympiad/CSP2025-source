#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200],s,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n*m;i++){
		scanf("%lld",&a[i]);
		if(a[i]>=a[0]) s++;
	}
	if(s%n!=0){
		if((s/n+1)%2==0) r=n-s%n+1;
		else r=s%n;
		printf("%lld %lld",s/n+1,r);
	}
	else{
		if((s/n)%2==0) r=1;
		else r=n;
		printf("%lld %lld",s/n,r);
	}
	return 0;
} 
