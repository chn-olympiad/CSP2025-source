#include<iostream>
#include<algorithm>
using namespace std;
int n , m , A[105] , cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>> n >> m;
	for(int i=1;i <= n*m;i++){
		cin>> A[i];
		if(A[i]>A[1])cnt++;
	}
	int x=1+ cnt/n;
	if(x&1){
		cout<< x <<' '<< 1+ cnt%n;
	}else{
		cout<< x <<' '<< n -cnt%n;
	}
	return 0;
}
