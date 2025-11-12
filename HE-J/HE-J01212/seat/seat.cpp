#include<bits/stdc++.h>
using namespace std;
int a[100];
int cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i ++){
		cin >> a[i];
	}
	int x = a[1];
	sort(a+1,a+1+n*m ,cmp);
	int booger = 0;
	for(int i = 1; i <= n*m; i ++){
		if(a[i] == x){
			booger = i;
			break;
		}
	}
	if(booger% m == 0){
		cout << booger/m;
	}else{
		cout << booger/m+1;
	}
	cout << " ";
	if(booger% m == 0){
		cout << n;
	}else{
		cout << booger %m;
	} 
	return 0;
}
