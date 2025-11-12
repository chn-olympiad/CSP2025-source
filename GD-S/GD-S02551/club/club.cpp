#include <bits/stdc++.h>
using namespace std;

long long t, n, a[100005][4], opt[100005], dif[100005];
long long cnt[4] = {0};
void mian(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		opt[i] = 0;
		for(int j = 1;j <= 3;j++)
			cin >> a[i][j];
	}
	cnt[1] = cnt[2] = cnt[3] = 0;
	long long tot = 0, lm = 0;
	for(int i = 1;i <= n;i++){
		if(a[i][1] > a[i][2] && a[i][1] > a[i][3])
			cnt[1]++, opt[i] = 1, tot += a[i][1];
		else if(a[i][2] > a[i][3])
			cnt[2]++, opt[i] = 2, tot += a[i][2];
		else
			cnt[3]++, opt[i] = 3, tot += a[i][3];
	}
	long long cur = 0;
	for(int j = 1;j <= 3;j++)
		if(cnt[j] > n / 2){
			for(int i = 1;i <= n;i++)
				if(opt[i] == j){
					long long mn = 1e9;
					for(int k = 1;k <= 3;k++)
						if(k != j)
							mn = min(mn, a[i][j] - a[i][k]);
					cur++, dif[cur] = mn;
				}
			lm = cnt[j] - n / 2;
			break;
		}
	sort(dif + 1, dif + cur + 1);
	for(int i = 1;i <= lm;i++)
		tot -= dif[i];
	cout << tot << endl;
	return ;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	for(int i = 1;i <= t;i++)
		mian();
	return 0;
} 
