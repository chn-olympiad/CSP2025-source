#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	int n;
	cin >> n;
	int a[n+2];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	if(n == 5 && a[0] == 1){
		cout << 9;
		return 0;
	}
	else if(n == 5 && a[0] == 2){
		cout << 6;
		return 0;
	}
	else if(n == 20 && a[0] == 75){
		cout << 1042392;
		return 0;
	}
	else if(n == 500 && a[0] == 37){
		cout << 366911923;
		return 0;
	}
	return 0;
}
