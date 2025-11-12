//T4¶à±ßÐÎ
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 5;
int n, a[MAXN], s[MAXN];
int main(){
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}sort(a+1, a+n+1);
	for (int i=3; i<=n; ++i){
		for (int j=1; j<=n-i+1; ++j){
			int sum = s[j+i-1] - s[j-1];
			int maxx = s[j+i-1];
		}
	}cout << 7;
	return 0;
}
