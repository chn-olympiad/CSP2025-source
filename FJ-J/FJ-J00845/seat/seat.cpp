#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n,m,r;
cin>>n>>m;
int a[n*m],seat[n][m];
for(int i = 1;i <= n*m;i++){
	cin>>a[i];
}
r = a[1];
for(int i = 1;i <=n*m;i++){
	int l;
	for(int j = 1;j <=n*m;j++){
		if(a[j]<a[i]){
			l = a[j];
			a[j] = a[i];
			a[i] = l; 
		}
	}
}
int number = 0;
for(int i = 1;i <= n*m;i++){
    if(r == a[i]){
    	number = i;
	}
} 
int n1;
if(number%n!=0){
	n1 = (number/n+1)*n;
	if(n1/n== 1 || n1/n<1){
		cout<<1<<" "<<number;
	}else if((n1/n)%2 == 0){
		cout<<n1/m<<" "<<number/n+1;
	}else {
		cout<<number/m+1<<" "<<number%n;
	}
}else if(number%n==0){
	if(number/n== 1 || number/n<1){
		cout<<1<<" "<<number;
	}else if((number/n)%2 == 0){
		cout<<number/m<<" "<<number%n+1;
	}else {
	cout<<number/m<<" "<<number/n;
}
 
}

 
return 0;
}
