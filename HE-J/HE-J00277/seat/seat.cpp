#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,r,c,o;
	cin >> n >>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	o=a[1];
	sort(a+1+n*m,a+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			if(i/n!=0){
			c=i/n;	
			}else{
			c=1;	
			}
			if(i<=n){
				r=i;
			}else if(i%n!=0){
				r=n-(i%n-1);
			}else if(i%n==0){
				if((i%n)%2!=0){
				r=n;	
				}else{
				r=1;	
				}						
			}		
		}
		break;
	}
	cout << c << r;
	return 0;
} 
