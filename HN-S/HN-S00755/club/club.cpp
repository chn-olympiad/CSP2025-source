#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][5], n;
void solve(){
	cin >> n;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			cin >> a[i][j];
		}
		if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) cnt1++;
		else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) cnt2++;
		else cnt3++;
	}
	int maxn = max(cnt1, max(cnt2, cnt3));
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += max(a[i][1], max(a[i][2], a[i][3]));
	}
	if(maxn > n / 2){
		int c = -1;
		if(maxn == cnt1) c = 1;
		else if(maxn == cnt2) c = 2;
		else c = 3;
		vector<int> v;
		for(int i = 1; i <= n; i++){
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3] && c == 1) 
				v.push_back(a[i][1] - max(a[i][2], a[i][3]));
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3] && c == 2)
				v.push_back(a[i][2] - max(a[i][1], a[i][3]));
			else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2] && c == 3)
				v.push_back(a[i][3] - max(a[i][1], a[i][2]));
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < maxn - n / 2; i++) sum -= v[i];
	}
	cout << sum << "\n";
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
} 
