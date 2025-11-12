#include <bits/stdc++.h> 
using namespace std;
long long n,k;
long long a[500005];
long long bnt(long long num , long long b){
	return 1;
}
int main (){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	long long num = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			num = bnt(num,a[i]);
		}
	}
	return 0;
}
