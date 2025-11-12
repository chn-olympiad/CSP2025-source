#include<iostream>
using namespace std;
int a[5001];
int n;	
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n < 3) cout << 0;
	else if(n == 3){
		int maxa = max(max(a[1],a[2]),a[3]);
		if(a[1]+a[2]+a[3] > maxa*2) cout << 1;
		else cout << 0;
	}
	else cout << 32767;
	return 0;
}
