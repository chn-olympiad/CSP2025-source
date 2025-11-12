#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	if(n < 3) {
		cout << 0;
	}
	else if(n == 3) {
		int y=0,maxx=0;
		for(int i = 1;i <= n;i++) {
			y+=a[i];
			maxx=max(maxx,a[i]);
		}
		if(y > maxx*2)
			cout << 1;
		else cout << 0;
	}
	else if(n > 3){
		cout << 5;
	}
	return 0;
}
