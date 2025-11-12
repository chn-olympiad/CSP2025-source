#include <iostream>
using namespace std;
int a[100]={0};
int main(){
	int r=0,c=1,n=0,m=0,sum=1;
	freopen(seat.in,n,stdin);
	freopen(seat.in,m,stdin);
	for(int i=0;i<n*m;i++){
		freopen(seat.in,a[i],stdin);
	}
	for(int j=1;j<n*m;j++){
		if(a[j]>a[0]){
			sum++;
		}
	}
	while(sum!=0){
		if(c%2==1){
			if(r!=n){
				r++;
				sum--;
			}else{
				c++;
				sum--;
				
			}
		}else{
			if(r!=1){
				r--;
				sum--;
			}else{
				c++;
				sum--;
			}
		}
	}
	freopen(seat.out,c,stdout);
	freopen(seat.out," ",stdout);
	freopen(seat.out,r,stdout);
	return 0;
}
