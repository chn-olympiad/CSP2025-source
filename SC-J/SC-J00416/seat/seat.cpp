#include<bits/c++io.h>
using namespace std;
int main(){
	int n,m,b,c,r,e,t;
	cin >> n,m;
	t=n*m+5;
	int a[t]
	for(int i=0;i<=n*m;i++){
		cin >> a[i];
	}
	for(int j=1;j<n*m-1;j++){
		for(int k=1;k< n*m-1;k++){
			if(a[k]>a[k+1]){
				e = a[k];
				a[k] = a[k+1];
				a[k+1] = e;
			}
	}
	for(int i=1;i<n*m;i++){
		if(a[0]>a[i]){
			b = i-1;
		}
	}
	c = b%%n+1;
	if (c%2=0){
		r=n - b%n;
	}
	else{
		r=b % n;
	}
	cuot<<c<<' ' <<r;
	return 0;
} 