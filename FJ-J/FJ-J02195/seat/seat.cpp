#include<bits/stdc++.h>
using namespace std;
int a[105];
int n, m;
bool wywdwrg(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)cin >> a[i];
	int p = a[1], o = 0;
	sort(a + 1, a + n * m + 1, wywdwrg);
	while(1){
		o++;
		if(a[o] == p)break;
	}
	int u = (o + n - 1) / n;
	cout << u << " ";
	o = o % (2 * n);
	if(o == 0)cout << "1";
	else if(u % 2 == 1)cout << o;
	else cout << 2 * n - o + 1;
	return 0;
} 
