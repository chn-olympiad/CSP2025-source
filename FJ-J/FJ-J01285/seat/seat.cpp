#include<bits/stdc++.h>
using namespace std;


bool cmp(int a,int b){
	return a > b;
} 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,tmp;
	cin >>n >>m; 
	int i2,a[n*m+1];
	for(int i = 1; i <= n*m; i++){
		cin >>a[i];
	}
	tmp = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++){
		if(tmp == a[i]){
			i2 = i;
			break;
		}
	} 
	if(i2 % n != 0){
		cout <<i2/n+1 <<" ";
		if((i2/n+1) % 2 == 0){
			cout <<n-i2%n+1;
		}else{
			cout <<i2%n;
		}
	}else{
		cout <<i2/n <<" ";
		if(i2/n % 2 == 0){
			cout <<1;
		}else{
			cout <<n;
		}
	}
	return 0;
}  
