#include<bits/stdc++.h> 
using namespace std;
//deque;
//vetor;
long long n,m,a,sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n*m;i++){
		long long y;
		scanf("%lld",&y);
		if(i==0)a=y;
		else if(y>a)sum++;
	}
	
	if((sum/n)%2==1){
		printf("%lld %lld",sum/n+1,m-(sum%n)+1);
	}
	else printf("%lld %lld",sum/n+1,(sum%n)+1);
	return 0;
}
