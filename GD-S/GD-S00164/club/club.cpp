#include <bits/stdc++.h>
using namespace std;
int sum[5], cnt = 0, a[10001];
struct node{
	int a, b, c;
}e[10001];
int n, m;
bool b11 = 0;
bool cmp(node a, node b){
	return a.a > b.b;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w",stdout);
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		if (n == 2){
			int a, b, c, a1, b1, c1;
			cin >> a >> b >> c >> a1 >> b1 >>c1;
			int a2 = max(a + b1, a + c1);
			int b2 = max(b + a1, b + c1);
			int c2 = max(c + b1, c + a1);
			a2 = max(a2, b2);
			c2 = max(a2, c2);
			cout << c2; 
		}
		for (int i = 1;i <= n;i++){
			int a, b, c;
			cin >> a >>b >> c;
			e[i].a = a;
			if (b||c){
				b11 = 1;
				break;
			}
		}
		if (b11 == 0){
			sort(e + 1, e + 1 + n, cmp); 
			for (int i = 1;i <= n / 2;i++){
				cnt += e[i].a;
			}
			cout << cnt;
		}
	}
	return 0;
} 
