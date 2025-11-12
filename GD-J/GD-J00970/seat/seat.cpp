#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> a[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n * m + 1);
	int i = 1, j = 1, k = n * m;
	for(; i <= n; i++){
		if(i % 2){
			for(j = 1; j <= m; j++, k--){
				if(a[k].second == 1){
					cout << i << ' ' << j;
					return 0;
				}
			}
		} else {
			for(j = m; j >= 1; j--, k--){
				if(a[k].second == 1){
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}
