#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int a[MAXN][5];
int t1[MAXN], t2[MAXN], t3[MAXN];
int T, n;
int ans;
bool cmpa(int x, int y){
	return x > y;
}
bool cmpb(int x, int y){
	return x < y;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				scanf("%d", &a[i][j]);
			}
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				cnt1++;
				ans += a[i][1];
				t1[cnt1] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
				continue;
			}
			if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				cnt2++;
				ans += a[i][2];
				t2[cnt2] = min(a[i][2] - a[i][1], a[i][2] - a[i][3]);
				continue;
			}
			if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2]){
				cnt3++;
				ans += a[i][3];
				t3[cnt3] = min(a[i][3] - a[i][1], a[i][3] - a[i][2]);
				continue;
			}
		}
		sort(t1 + 1, t1 + cnt1 + 1, cmpb);
		sort(t2 + 1, t2 + cnt2 + 1, cmpb);
		sort(t3 + 1, t3 + cnt3 + 1, cmpb);
		int x, id;
		if(cnt1 >= cnt2 && cnt1 >= cnt3){
			x = cnt1;
			id = 1;
			if(x > n / 2){
				x -= n / 2;
				for(int i = 1; i <= x; i++){
					ans -= t1[i];
				}
			}
		}
		if(cnt2 >= cnt1 && cnt2 >= cnt3){
			x = cnt2;
			id = 2;
			if(x > n / 2){
				x -= n / 2;
				for(int i = 1; i <= x; i++){
					ans -= t2[i];
				}
			}
		}
		if(cnt3 >= cnt1 && cnt3 >= cnt2){
			x = cnt3;
			id = 3;
			if(x > n / 2){
				x -= n / 2;
				for(int i = 1; i <= x; i++){
					ans -= t3[i];
				}
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}