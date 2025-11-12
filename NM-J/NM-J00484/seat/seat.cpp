#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n=0;
	long long m=0;
	long long a[105]={};
	scanf("%lld"'lld',&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%lld",&a[i]);
	}
	int x=n*m;
	for(int i=0;i<x;i++){
		if(a[i]>a[i+1]){
			a[1]=a[i];
			x++;
		}else {
			continue;
		}
		if (x>n){
			
		}
		if(a[i]==x){
			printf("%lld" "lld",n,m);
			x--;
			break;
		}else if(a[i]==x){
			printf("%lld" "lld",n,m);
			break;
		}
	}
	return 0;
}
