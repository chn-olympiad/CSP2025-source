#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long su=0;
long long a[105];
long long summ=1;
long long anx,any;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	scanf("%lld",&a[1]);
	for(int i=2;i<=n*m;i++){
		scanf("%lld",&a[i]);
		if(a[i]>a[1]) summ++;
	}
	if(summ%n==0){
		anx=summ/n;
	}
	else{
		anx=summ/n+1;
	}
	if(anx%2==1){
		any=summ%m;
		if(any==0){
			any=n;
		}
	}
	else{
		if(summ%m==0){
			any=1;
		}
		else{
			any=n-summ%m+1;
		}
	}
	printf("%lld %lld",anx,any);
	return 0;
}
