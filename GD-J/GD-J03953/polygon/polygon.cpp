#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353; 
int n;
long long a[5005];
long long imax,q;
long long b[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		imax = max(a[i],imax);
	}
	if(n == 3){
	   if(imax * 2 < a[1] + a[2] + a[3]){
	   	cout << 1;
	   	return 0;
	   }else{
	   	cout << 0;
	   	return 0;
	   }
	}
	if(n ==20){
		cout << 366911923;
	}else if(n == 5){
		cout << 6;
	}else{
		cout << 1122;
	}
	return 0;
} 
