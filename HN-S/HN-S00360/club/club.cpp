#include<bits/stdc++.h>
using namespace std;
int t, n, a[100005][5];
int ans1 = 0, ans2 = 0, ans3 = 0;
struct node{
	int c1, c2, c3;
	int x1, x2;
}m[100005];
bool cmp(int x, int y){
	return x > y;
}
bool cmp1(node x, node y){
	return x.c1 > y.c1;
}
bool cmp2(node x, node y){
	return x.c2 > y.c2;
}
bool cmp3(node x, node y){
	return x.c3 > y.c3;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		a[0][1] = 0, a[0][2] = 0, a[0][3] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			m[i].c1 = a[i][1] - a[i][2], m[i].c2 = a[i][2] - a[i][3], m[i].c3 = a[i][3] - a[i][1];
		}
		//
		int cnt2 = 0, cnt3 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i][2] == 0) cnt2++;
			if(a[i][3] == 0) cnt3++;
		}
		if(cnt2 == n && cnt3 == n){
			int ans = 0, b[100005];
			for(int i = 1; i <= n; i++) b[i] = a[i][1];
			sort(b + 1, b + n + 1, cmp);
			for(int i = 1; i <= n / 2; i++) ans += b[i];
			cout << ans << "\n";
			continue;
		}
		if(cnt3 == n){
			int ans = 0;
			for(int i = 1; i <= n; i++){
				m[i].x1 = a[i][1];
				m[i].x2 = a[i][2];
			}
			sort(m + 1, m + n + 1, cmp1);
			for(int i = 1; i <= n / 2; i++) ans += m[i].x1;
			for(int i = n / 2 + 1; i <= n; i++) ans += m[i].x2;
			cout << ans << "\n";
			continue;
		}
		// //
		if(n == 2){
			int max1 = -1, mxi1;
			int max2 = -1, mxi2;
			for(int i = 1; i <= 3; i++){
				if(a[1][i] > max1){
					max1 = a[1][i];
					mxi1 = i;
				}
			}
			for(int i = 1; i <= 3; i++){
				if(a[2][i] > max2){
					max2 = a[2][i];
					mxi2 = i;
				}
			}
			if(mxi1 != mxi2) cout << max1 + max2 << "\n"; 
			else{
				int mid1 = -1, mid2 = -1;
				for(int i = 1; i <= 3; i++){
					if(i = mxi1) continue;
					mid1 = max(mid1, a[1][i]);
				}
				for(int i = 1; i <= 3; i++){
					if(i = mxi2) continue;
					mid2 = max(mid2, a[2][i]);
				}
				cout << max(max1, max2) + max(mid1, mid2) << "\n";
			}
			continue;
		}
		// //
		sort(m + 1, m + n + 1, cmp1);
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){ //第i个人之前进1社团 第j个人之前进2社团 第j个人及以后进3社团 下同 
				int s1 = 0;
				for(int k = 0; k < i; k++) s1 += a[k][1];
				for(int k = i; k < j; k++) s1 += a[k][2];
				for(int k = j; k <= n; k++) s1 += a[k][3];
				ans1 = max(ans1, s1);
			}
		}
		//
		sort(m + 1, m + n + 1, cmp2);
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				int s2 = 0;
				for(int k = 0; k < i; k++) s2 += a[k][1];
				for(int k = i; k < j; k++) s2 += a[k][2];
				for(int k = j; k <= n; k++) s2 += a[k][3];
				ans2 = max(ans2, s2);
			}
		}
		//
		sort(m + 1, m + n + 1, cmp3);
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				int s3 = 0;
				for(int k = 0; k < i; k++) s3 += a[k][1];
				for(int k = i; k < j; k++) s3 += a[k][2];
				for(int k = j; k <= n; k++) s3 += a[k][3];
				ans3 = max(ans3, s3);
			}
		}
		cout << max(ans1, max(ans2, ans3)) << "\n";
	}
	return 0;
}
