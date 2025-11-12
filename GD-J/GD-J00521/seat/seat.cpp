#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,z,sum;
long long ar;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&z);
	sum=1;
	for(int i=2;i<=n*m;i++){
		scanf("%lld",&ar);
		if(ar>z){
			sum++;
		}
	}
	x=(sum-1)/n+1;
	if(x%2==1){
		y=(sum-1)%n+1;
	}
	else{
		y=x*n-sum+1;
	} 
	printf("%lld",x);
	cout<<" ";
	printf("%lld",y);
	


	return 0;
}

