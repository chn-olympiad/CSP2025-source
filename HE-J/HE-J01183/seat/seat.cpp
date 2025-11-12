#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,a,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(long long i=2;i<=n*m;i++){
		scanf("%ld",&x);
		if(x>a)ans++;
	}
	long long y=(ans+n-1)/n;
	x=ans%n;
	if(x==0)x=n;
	if(y%2==1){
		printf("%ld %ld",y,x);
	}else{
		printf("%ld %ld",y,(n+1-x));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
