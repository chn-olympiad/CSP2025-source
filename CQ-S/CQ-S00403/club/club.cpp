#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;
pii a[MAXN][4];
int bel[MAXN], cnt[4], del[MAXN];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		cnt[1] = cnt[2] = cnt[3] = 0;
		int ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1].F >> a[i][2].F >> a[i][3].F;
			a[i][1].S = 1;
			a[i][2].S = 2;
			a[i][3].S = 3;
			sort(a[i] + 1, a[i] + 4);
			bel[i] = a[i][3].S;
			cnt[a[i][3].S]++;
			ans += a[i][3].F;
		}
		int idx = 0;
		if(cnt[1] > n / 2) idx = 1;
		else if(cnt[2] > n / 2) idx = 2;
		else if(cnt[3] > n / 2) idx = 3;
		if(idx == 0){
			cout << ans << "\n";
			continue;
		}
		int t = 0;
		for(int i = 1; i <= n; i++)
			if(bel[i] == idx) del[++t] = a[i][3].F - a[i][2].F;
		sort(del + 1, del + t + 1);
		for(int i = 1; i <= cnt[idx] - n / 2; i++) ans -= del[i];
		cout << ans << "\n";
	}
	return 0;
}
