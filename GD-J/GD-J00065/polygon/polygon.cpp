#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e3 + 10;
int a[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) cout << 1;
	else cout << 0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
