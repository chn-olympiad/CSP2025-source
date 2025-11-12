#include <bits/stdc++.h>
using namespace std;
struct node{
	int a, b;
}a[1005];
int n, m;
bool cmp(node x, node y){
	return x.b > y.b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].b;
		a[i].a = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i].a == 1){
			int b;
			if(i % n == 0){
				 b = i / n;
				 cout << b << " " << n;
				 continue;
			 }
			else b = i / n + 1;
			cout << b << " ";
			if(b % 2 == 1) cout << i % n;
			else cout << n - i % n + 1;
			break;
		}
	}
	return 0;
}
