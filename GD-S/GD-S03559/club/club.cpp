#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, an;
	int fi = 1, se = 2, th = 3;
	cin >> t;
	int n, a[10010][5], ans[10], d[10010], mi[10010], ma[10010][5];
	for(int i = 1; i <= t; i++){
		cin >> n;
		int l = n / 2;
		int tr[n];
		for(int j = 1; j <= n; j++){
			cin >> a[j][fi];
			cin >> a[j][se];
			cin >> a[j][th];
			tr[j] = 1;
		}
		if(n == 2){
			for(int j = 1; j <= n; j++){
				if(a[j][fi] >= a[j][se] && a[j][se] >= a[j][th]){
					ma[j][fi] = a[j][fi];
					ma[j][se] = a[j][se];
					ma[j][th] = a[j][th];
					d[j] = fi;
				}
				if(a[j][fi] >= a[j][th] && a[j][th] >= a[j][se]){
					ma[j][fi] = a[j][fi];
					ma[j][se] = a[j][th];
					ma[j][th] = a[j][se];
					d[j] = fi;
				}
				if(a[j][se] >= a[j][fi] && a[j][fi] >= a[j][th]){
					ma[j][fi] = a[j][se];
					ma[j][se] = a[j][fi];
					ma[j][th] = a[j][th];
					d[j] = se;
				}
				if(a[j][se] >= a[j][th] && a[j][th] >= a[j][fi]){
					ma[j][fi] = a[j][se];
					ma[j][se] = a[j][th];
					ma[j][th] = a[j][fi];
					d[j] = se;
				}
				if(a[j][th] >= a[j][se] && a[j][se] >= a[j][fi]){
					ma[j][fi] = a[j][th];
					ma[j][se] = a[j][se];
					ma[j][th] = a[j][fi];
					d[j] = th;
				}
				if(a[j][th] >= a[j][fi] && a[j][fi] >= a[j][se]){
					ma[j][fi] = a[j][th];
					ma[j][se] = a[j][fi];
					ma[j][th] = a[j][se];
					d[j] = th;
				}
			}
			if(d[1] == d[2]){
				ans[i] = max(ma[1][fi] + ma[2][se], ma[1][se] + ma[2][fi]);
			}
			else{
				ans[i] = ma[1][fi] + ma[2][fi];
			}
		}
		else{
			for(int j = 1; j <= n; j++){
				if(a[j][fi] >= a[j][se] && a[j][se] >= a[j][th]){
					ma[j][fi] = a[j][fi];
					ma[j][se] = a[j][se];
					ma[j][th] = a[j][th];
					d[j] = fi;
				}
				if(a[j][fi] >= a[j][th] && a[j][th] >= a[j][se]){
					ma[j][fi] = a[j][fi];
					ma[j][se] = a[j][th];
					ma[j][th] = a[j][se];
					d[j] = fi;
				}
				if(a[j][se] >= a[j][fi] && a[j][fi] >= a[j][th]){
					ma[j][fi] = a[j][se];
					ma[j][se] = a[j][fi];
					ma[j][th] = a[j][th];
					d[j] = se;
				}
				if(a[j][se] >= a[j][th] && a[j][th] >= a[j][fi]){
					ma[j][fi] = a[j][se];
					ma[j][se] = a[j][th];
					ma[j][th] = a[j][fi];
					d[j] = se;
				}
				if(a[j][th] >= a[j][se] && a[j][se] >= a[j][fi]){
					ma[j][fi] = a[j][th];
					ma[j][se] = a[j][se];
					ma[j][th] = a[j][fi];
					d[j] = th;
				}
				if(a[j][th] >= a[j][fi] && a[j][fi] >= a[j][se]){
					ma[j][fi] = a[j][th];
					ma[j][se] = a[j][fi];
					ma[j][th] = a[j][se];
					d[j] = th;
				}
				an = an + ma[j][fi];
			}
			ans[i] = an;
		}
	}
	for(int i = 1; i <= t; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
