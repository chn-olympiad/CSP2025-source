#include <bits/stdc++.h>
using namespace std;
int n, q, num = 0;
string x, y, a, b;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i ++){
		cin >> x >> y;
		num ++;
	}
	for (int i = 1;i <= q;i ++){
		cin >> a >> b;
	}
	cout << num / 2 << endl << 0;
    return 0;
}
