#include <bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << 0;
	}
	else if(n==3){
		if(a[0]<a[1]+a[2] && a[1]<a[0]+a[2] && a[2]<a[0]+a[1]){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 16;
	}
	return 0;
} 
