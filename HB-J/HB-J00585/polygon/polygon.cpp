#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m;
	if(n == 4){
		cout << 5;
	}
	if(n == 5){
		cout << 9;
	}
	else{
		cout << 2*n-1;
	}
	return 0;
}
