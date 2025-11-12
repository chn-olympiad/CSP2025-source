#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, h = 1, g = 1;
struct nod{
	int x, id;
}a[110];

bool cmp(nod p, nod q){
	return p.x > q.x;
}

signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i].x;
		a[i].id = i;
	}
	sort (a + 1, a + n * m + 1, cmp);
	/*for (int i = 1; i <= n * m; i++){
		cout << a[i].x << " " << a[i].id << endl;
	}*/
	for (int i = 1; i <= n * m; i++){
		//cout << a[i].x << " " << a[i].id << endl;
		if (a[i].id == 1){
			cout << h << " ";
			if (h % 2 == 0) cout << n - g + 1 << endl;
			else cout << g << endl;
			break;
		}
		if (g == n){
			g = 1;
			h++;
		}else{
			g++;
		}
	}
	return 0;
}
