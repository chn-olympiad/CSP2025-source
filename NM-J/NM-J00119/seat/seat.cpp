#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a[105],t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	t = n*m;
	cin >> a[1];
	int flag = a[1];
	for(int i = 2;i <= t;i++){
		cin >> a[i];
	}
	sort(a+1,a+t+1,cmp);
	for(int i = 1;i <= t;i++){
		if(a[i] == flag);
		flag = i;
	}
			
	if(flag % (2 * n) > n){
		r = flag % (2 * n) ; ;
		if(flag % (m*n / m) != 0){
			c = flag / (m*n / m) + 1; 
		}
		else{
			c = flag / (m / n);
		}
	}
	else if(flag % (2 * n) <= n){
		r = flag % (2 * n) ;
		if(flag % (m*n / m) != 0){
			c = flag / (m*n / m) + 1; 
		}
		else{
			c = flag / (m / n);
	}
	}	
	else{
		r = n;
		c = flag / (m / n);
	}
	cout << c/3<<" "<< r/3;
	return 0;
}

