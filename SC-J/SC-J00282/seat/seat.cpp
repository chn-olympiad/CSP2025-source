#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int cj;
	int c, r;
	int idx;
}a[10010];
bool cmp(node x, node y){
	return x.cj > y.cj;
}
int n, m;
signed main(){
	freopen("seat.in","r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%lld", &a[i].cj);
		a[i].idx = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i].idx == 1){
			//cout << i << endl;
			if(i % n == 0){
				if((i / n) % 2 == 0){
					cout << i / n << " " << 1 <<endl;
					break;
				}
				cout << i / n << " " << n << endl;
				break;
			}
			if((i / n + 1) % 2 == 0){
				cout << i / n + 1 << " " << n - i % n + 1 << endl;
				break;
			}
			cout << i / n + 1 << " " << i % n << endl;
			break;
		}
	}
	return 0;
}