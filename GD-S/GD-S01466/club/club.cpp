#include <bits/stdc++.h>
using namespace std;

int arr[100005][3], ans, n;
int te[3];
int mx[100005], ma[100005];
int an[100005];
int ou[100005];

void dfs(int a, int nans){
	if (a > n){
		ans = max(ans, nans);
		if (ans == nans)
		for (int i = 1;i <= n;i++)    ou[i] = an[i];
		return;
	}
	if (nans + ma[n] - ma[a - 1] < ans)    return;
	else {
		for (int i = 0;i <= 2;i++){
			if (te[i] + 1 > n / 2)    continue;
			te[i] += 1;
			an[a] = i;
			dfs(a + 1, nans + arr[a][i]);
			te[i] -= 1;
		}
	}    
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(te, 0, sizeof(te));
		memset(mx, 0, sizeof(mx));
		memset(ma, 0, sizeof(ma));
		ans = 0;
		for (int i = 1;i <= n;i++){
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			mx[i] = max(max(arr[i][0], arr[i][1]), arr[i][2]);
			ma[i] = ma[i - 1] + mx[i];
		}
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
} 
