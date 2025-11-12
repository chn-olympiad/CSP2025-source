#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 20;
int t, n, cnt1, cnt2, cnt3, a[N][5], num[N];
ll ans;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t --){
		scanf("%d", &n);
		ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for(int i = 1; i <= n; i++) scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		for(int i = 1; i <= n; i++){
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) cnt1 ++;
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) cnt2 ++;
			else cnt3 ++;
			ans += max(a[i][1], max(a[i][2], a[i][3]));
		}
		if(cnt1 > n / 2){
			int cnt = cnt1 - n / 2, numsiz = 0;
			for(int i = 1; i <= n; i++){
				if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
					num[++ numsiz] = a[i][1] - max(a[i][2], a[i][3]);
				}
			}
			sort(num + 1, num + cnt1 + 1);
			for(int i = 1; i <= cnt; i++) ans -= num[i];
		}
		else if(cnt2 > n / 2){
			int cnt = cnt2 - n / 2, numsiz = 0;
			for(int i = 1; i <= n; i++){
				if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
					num[++ numsiz] = a[i][2] - max(a[i][1], a[i][3]);
				}
			}
			sort(num + 1, num + cnt2 + 1);
			for(int i = 1; i <= cnt; i++) ans -= num[i];
		}
		else if(cnt3 > n / 2){
			int cnt = cnt3 - n / 2, numsiz = 0;
			for(int i = 1; i <= n; i++){
				if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2]){
					num[++ numsiz] = a[i][3] - max(a[i][1], a[i][2]);
				}
			}
			sort(num + 1, num + cnt3 + 1);
			for(int i = 1; i <= cnt; i++) ans -= num[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}