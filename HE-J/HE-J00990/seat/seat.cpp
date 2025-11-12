#include<bits/stdc++.h>
using namespace std;
char a[10005];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[n*m];
	cout << n << " " << n*m-m;
	return 0;
}
