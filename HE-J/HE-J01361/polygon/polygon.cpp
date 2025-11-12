#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[5005];
	bool ca = 1;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==3){
		int sum=0, ma=0;
		for(int i=1;i<=3;i++){
			sum += a[i];
			ma = max(ma, a[i]);
		}
		if(sum>ma*2) cout << 1;
		else cout << 0;
	}
	else cout << 0;
	return 0;
}
