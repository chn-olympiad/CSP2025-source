#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, num=1, x, y;
	cin >> n >> m ;
	cin >> x ;
	for(int i=1;i<=n*m-1;i++){
		cin >> y ;
		if(y>x){
			num++;
		}
	}
	if(num%n==0){
		cout << num/n << " " ;
		if(num/n%2==0){
			cout << "1" ;
		}else{
			cout << n ;
		}
		return 0;
	}else{
		cout << num/n+1 << " " ;
		if((num/n+1)%2==0){
			cout << n-num%n+1 ;
		}else{
			cout << num%n ;
		}
		return 0;
	}

	return 0;

}
