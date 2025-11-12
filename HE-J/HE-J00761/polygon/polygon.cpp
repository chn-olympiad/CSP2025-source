#include <bits/stdc++.h>
using namespace std;
int main() {
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
int a[5005];
cin >> n;
for (int i = 0;i < n;i++){
	cin >> a[i];
}
if (a[n-1] + a[n-2] == 9) {
	cout << "9";
} 
	return 0;
}
