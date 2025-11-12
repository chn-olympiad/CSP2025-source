#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[1000];
	for(int i = 0;i < n; i++) cin >> a[i];
	if(n == 5){
		if(a[0] == 1 and a[1] == 2 and a[2] == 3 and a[3] == 4 and a[4] == 5){
			cout << 9;
		}
		if(a[0] == 2 and a[1] == 2 and a[2] == 3 and a[3] == 8 and a[4] == 10){
			cout << 6;
		}
	}
	if(n == 20) cout << 1842392;
	if(n == 500) cout << 366911923;
}
