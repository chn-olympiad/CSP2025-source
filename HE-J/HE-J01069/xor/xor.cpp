#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;

long long a[1006], n, m;
int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	cout<<n;
	return 0;
} 
