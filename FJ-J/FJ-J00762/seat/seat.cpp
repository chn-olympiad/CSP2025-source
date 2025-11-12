#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn = 15;
int a[maxn * maxn];
int t = 0;
int ans = 0;
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if(i == 1) t = a[i];
	}
	int h = 1,l = 1;
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n;i++) {
		if(i % 2 == 1) sort(a + n * (i - 1) + 1,a + n * i + 1,cmp);
		else sort(a + n * (i - 1) + 1,a + n * i + 1);
	}
	for(int i = 1; i <= n * m; i++) {
		if(a[i] == t) {
			cout << h << " " << l << endl;
			exit(0);
		}
		if(l == m) {
			h++;
			l = 1;
		} else l++;

	}
	return 0;
}
