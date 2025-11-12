#include<bits/stdc++.h>
using namespace std;

long long inf = 999999999;
long long T, n, a[100005][3], ans, di[100005], tot[3], flag = -1;

long long cmax(long long k){
	return a[k][0] + a[k][1] + a[k][2] - max(a[k][0], max(a[k][1], a[k][2])) - min(a[k][0], min(a[k][1], a[k][2]));
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][0] >= a[i][1] && a[i][1] >= a[i][2]){
				tot[0]++;
				ans += a[i][0];
			}
			else if(a[i][0] >= a[i][2] && a[i][2] >= a[i][1]){
				tot[0]++;
				ans += a[i][0];
			}
			else if(a[i][1] >= a[i][0] && a[i][0] >= a[i][2]){
				tot[1]++;
				ans += a[i][1];
			}
			else if(a[i][1] >= a[i][2] && a[i][2] >= a[i][0]){
				tot[1]++;
				ans += a[i][1];
			}
			else if(a[i][2] >= a[i][1] && a[i][1] >= a[i][0]){
				tot[2]++;
				ans += a[i][2];
			}
			else if(a[i][2] >= a[i][0] && a[i][0] >= a[i][1]){
				tot[2]++;
				ans += a[i][2];
			}
		}
		if(tot[0] > n/2)
			flag = 0;
		if(tot[1] > n/2)
			flag = 1;
		if(tot[2] > n/2)
			flag = 2;
		if(flag != -1){
			for(int i = 1; i <= n; i++){
				if(a[i][flag] == max(a[i][0], max(a[i][1], a[i][2])))
					di[i] = a[i][flag] - cmax(i);
				else
					di[i] = inf;
			}
			sort(di + 1, di + n + 1);
			for(int i = n/2 + 1; i <= tot[flag]; i++){
				ans -= di[i - n/2];
			}
		}
		cout << ans << "\n";
		ans = 0; tot[0] = 0; tot[1] = 0; tot[2] = 0;
		memset(di, 0, sizeof(di));
	}
	return 0;
}
