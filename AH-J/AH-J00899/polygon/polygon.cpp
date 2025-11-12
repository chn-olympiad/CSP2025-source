#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];

int main(){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	if (n == 3){
		int x = a[0], y = a[1], z = a[2];
		if (x + y > z && x + z > y && y + z > x){
			cout << x + y + z<< endl;
			return 0;
		}
	}
	
	return 0;
}
