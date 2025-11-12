#include<bits/stdc++.h>
using namespace std;
bool Cpm(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	int A[110];
	cin>>n>>m;
	for(int i = 1 ; i <= m * n ; i++)
		cin>>A[i];
	int a = A[1] , flag;
	sort(A + 1 , A + n * m + 1 , Cpm);
	for(int i = 1 ; i <= m * n ; i++){
		if(A[i] == a) flag = i;
	}
	int x;
	if(flag % n == 0){
		cout<<flag / n<<" ";
		x = flag / n;
	}
	else{
		cout<<flag / n + 1<<" ";
		x = flag / n + 1;
	}
	if(x % 2 == 1){
		cout<<flag - (x - 1) * n;
	}
	else{
		cout<<n - (flag - (x - 1) * n) + 1;
	}
	return 0;
}
