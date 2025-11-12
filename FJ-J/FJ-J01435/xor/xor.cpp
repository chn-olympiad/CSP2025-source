#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long M = 2 << 20;
int n , k , a[N];
int num1 , num2;
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] == 1) num1 ++;
		if(a[i] == 0) num2 ++;
	}
	if(k == 1){
		cout << num1 << endl;
	}
	else if(k == 0) cout << num2 << endl;
	else cout << 0 << endl;
	return 0;
}

