#include <bits/stdc++.h>
using namespace std;
long long t, a[100005][6], b[100005][5], num[5];
struct WH{
	long long id, ib;
} wh[100005];
void mx1(long long i, long long x, long long y, long long z){
	if (x >= y){
		if (x >= z){
			b[i][1] = 1;
			if (y >= z){
				b[i][2] = 2;
				b[i][3] = 3;
			}
			else{
				b[i][2] = 3;
				b[i][3] = 2;
			}
		}
		else{
			b[i][1] = 3;
			b[i][2] = 1;
			b[i][3] = 2;
		}
	}
	else{
		if (y >= z){
			b[i][1] = 2;
			if (x >= z){
				b[i][2] = 1;
				b[i][3] = 3;
			}
			else{
				b[i][2] = 3;
				b[i][3] = 1;
			}
		}
		else{
			b[i][1] = 3;
			b[i][2] = 2;
			b[i][3] = 1;
		}
	}
}
bool cmp(WH x, WH y){
	return x.id < y.id;
}
int main(){
	freopen("club.in", "w", stdin);
	freopen("club.out", "r", stdout);
	cin >> t;
	while (t--){
		long long n, m = 0, sum = 0;
		memset(num, 0, sizeof(num));
		cin >> n;
		m = n / 2;
		for (long long i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			mx1(i, a[i][1], a[i][2], a[i][3]);
			wh[i].id = a[i][b[i][1]] - a[i][b[i][2]];
			wh[i].ib = i;
			num[b[i][1]]++;
			sum += a[i][b[i][1]];
		}
		sort(wh + 1, wh + n + 1, cmp);
		long long v = 0;
		if (num[1] > m) v = 1;
		else if (num[2] > m) v = 2;
		else if (num[3] > m) v = 3;
		while (num[v] > m){
			for (int i = 1; i <= n; i++){
				if (b[wh[i].ib][1] == v){
					sum -= wh[i].id;
					num[v]--;
					break;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
