#include<bits/stdc++.h>
using namespace std;
int m,n,a[107],k,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++){
		cin >> a[i];
	}k = a[1];
	sort(a+1,a+1+n*m);
	for(int i = 1;i<=n*m;i++){
		if(a[i]==k){
			p = n*m-i+1;
		}
	}if(p%n==0){
		if(p/n%2==0){
			cout << p/n << ' ' << 1;
		}else{
			cout << p/n << ' ' << n;
		}return 0;
	}else{
		if(p/n%2!=0){
			cout << p/n+1 << ' ' << n-p%n+1;
		}else{
			cout << p/n+1 << ' ' << p%n;
		}
	}
	return 0;
} 
