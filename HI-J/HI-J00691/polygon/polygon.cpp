#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int b,c,a[100],ans;
	cin >> b;
	for(int i = 0;i < b;i++){
		cin >> a[i];
	}
	for(int i = 0;i < b;i++){
		if(a[i - 2] > a[i]+a[i-1]) ans++;
	}
	cout << ans + a[3] + a[3];
	return 0;
}

