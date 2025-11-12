#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5005], n, maxa, ans, cnt;
bool sss = true;
int main(){
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
		cnt += a[i];
		maxa = max(maxa, a[i]);
		if (a[i] != 1) {
			sss = false;
		}
	}
	if (sss) {
		cout<<((1 + n - 2) * (n - 2)) / 2;
		return 0;
	}
	if (cnt > maxa * 2) {
		cout<<cnt;
		return 0;
	}
	cout<<0;
	return 0;
} 
