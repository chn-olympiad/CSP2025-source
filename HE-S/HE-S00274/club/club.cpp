#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int M = 1e5 + 5;

int t , n;
int a[N] , maxn[M] , st[N];;
bool vis[N];

bool cmp(int x , int y) {
	return x > y;
}

int main() {
	
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	
	cin >> t;
	while(t --) {
		int cnt = 0;
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i] >> a[i + 1] >> a[i + 2];
			maxn[i] = max(a[i] , max(a[i + 1] , a[i + 2]));
			if(maxn[i] == a[i]) cnt ++;
		}
		sort(maxn + 1 , maxn + n + 1 , cmp);
		if(cnt > n / 2) {
			for(int i = 1; i <= n / 2; i++) ans += maxn[i];
		}
		cout << ans << endl;
	}
	
	return 0;
} 
// rp ++
