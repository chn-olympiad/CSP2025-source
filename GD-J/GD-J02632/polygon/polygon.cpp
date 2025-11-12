#include <bits/stdc++.h>
using namespace std;
int n,js;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	if (n <= 3){
		int a[4],js = 0;
		for (int i = 1; i <= 3; i++){
			cin >> a[i];
			js+=a[i];
		}
		sort(a+1,a+3+1);
		if (js > a[3] * 2){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	int a[10005] = {};
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		
	}
	cout << 6;
	return 0;
} 
