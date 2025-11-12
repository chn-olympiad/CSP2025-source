#include <iostream>
using namespace std;
const long long m=998244353;
long long a[10001]={0};
int main(){
	long long int sum=1;
	int n=0;
	freopen(polygon.in,n,stdin);
	for(int j=0;j<n;j++){
		freopen(polygon.in,a[j],stdin);
	}
	for(int i=0;i<n;i++){
		sum*=2;
	}
	sum-=1;
	sum-=n;
	sum-=(n*(n-1)/2);
	sum%=m;
	freopen(polygon.out,sum,stdout);
	return 0;
} 
