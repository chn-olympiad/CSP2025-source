#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	n = 3;
	int a[4];
	int maxa = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] > maxa){
			maxa = a[i];
		}
	}
	if((a[1]+a[2]+a[3]) > (maxa*2)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}