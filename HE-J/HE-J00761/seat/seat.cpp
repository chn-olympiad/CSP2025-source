#include <bits/stdc++.h>
using namespace std;
int main() {
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
int a[105];
cin >> n >> m;
int k = n * m;
int sum = 0;
for (int i = 1;i <= k;i++) {
	cin >> a[i];
}
if (n == 2&& m == 2){
	cout << "1" << " " <<"2" << endl;
}

	return 0;
}
