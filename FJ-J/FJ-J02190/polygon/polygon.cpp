#include<bits/stdc++.h>
using namespace std;
long long n , a[5050] , ooo[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	if(n==3){
		cout << 1;
		return 0; 
	}

	ooo[1] = 1; 
	for(long long i = 2 ; i <= n ; i++){
		ooo[i] = i * ooo[i-1];
	}
	cout << (ooo[n]) / (ooo[3] * ooo[n-3]);
	return 0;
}
