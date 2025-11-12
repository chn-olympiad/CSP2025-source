#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000010;
struct kun {
	int id;
	int w;
}suan[N];
bool vmp(kun x, kun y) {
	return x.w > y.w;
}
int cnt = 1, n, m;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m; 
	int zhi = n * m;
	for(int i = 1;i <= zhi;i ++) {
		suan[i].id = i;
		cin >> suan[i].w;
	} 
	sort(suan + 1, suan + 1 + zhi, vmp);
	int x = 1, y = 1, sum = 1;
	while(cnt <= zhi) {
		if(suan[cnt].id == 1) {
			cout << y << " " << x << endl;
			break;
		}
		else if((x == n && sum == 1) || (x == 1 && sum == -1)) {
			if(x == n) sum = -1;
			else sum = 1;
			y ++;
		} else {
			x += sum;
		} cnt ++;
	}
	return 0;
} 
