#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10001];
bool cmp(int b,int c) {
	return b > c;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= m*n;i++) {
		cin >> a[i];
	}
	int awa = a[1];
	int w = 10000;
	int x = 10000;
	sort(a+1,a+1+m*n,cmp);
	for(int i = 1;i <= m*n;i++) {
		if(a[i] == awa) {
			w = i;
			if(i % n == 0) {
				x = i / n;
			}else{
				x = i / n + 1;
			}
			break;
		}
	}
	cout << x << " "; 
	if(x % 2 != 0) {//ÆæÊýÅÅ 
		if(w % n == 0) {
			cout << n;
		}else{
			cout << w % n;
		}
	}else {
		if(w % n == 0) {
			cout << 1;
		}else{
			cout << n - (w % n) + 1;
		}
	}
	return 0;
}
