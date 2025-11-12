#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
int T, n;
int a[N], b[N], c[N];
int ans = 0, cnt = 0, x;
int cntt = 0;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		x = n / 2;
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		for(int i = 1; i <= n; i++){
			if(a[i] == 0 && b[i] == 0 && c[i] == 0){
				ans = 0;
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] != 0 && b[i] == 0 && c[i] == 0){
				sort(a + 1, a + n + 1, cmp);
				ans += a[i];
				cnt++;
				if(cnt == x){
					break;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] == 0 && b[i] != 0 && c[i] == 0){
				sort(b + 1, b + n + 1, cmp);
				ans += b[i];
				cnt++;
				if(cnt == x){
					break;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] != 0 && b[i] != 0 && c[i] == 0){
				int m = max(a[i], b[i]);
				ans += m;
				cnt++;
				if(cnt == x){
					if(m == a[i]){
						ans += b[i + 1];
					} else {
						ans += a[i + 1];
					}
					break;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] != 0 && b[i] != 0 && c[i] != 0){
				int m = max(a[i], b[i]);
				int mm = max(m, c[i]);
				ans += mm;
				cnt++;
				if(cnt == x){
					if(mm == a[i]){
						int mmm = max(b[i + 1], c[i + 1]);
						ans += mmm;
						cntt++;
						if(cntt == x){
							if(mmm == b[i + 1]){
								ans += c[i + 2];
							} else {
								ans += b[i + 2];
							}
							
						}
						break;
					} else if(mm == b[i]){
						int mmm = max(a[i + 1], c[i + 1]);
						ans += mmm;
						cntt++;
						if(cntt == x){
							if(mmm == a[i + 1]){
								ans += c[i + 2];
							} else {
								ans += a[i + 2];
							}
						}
						break;
					} else {
						int mmm = max(a[i + 1], b[i + 1]);
						ans += mmm;
						cntt++;
						if(cntt == x){
							if(mmm == a[i + 1]){
								ans += b[i + 2];
							} else {
								ans += a[i + 2];
							}
						}
						break;
					}
				}
			}
		}
		cout << ans << endl;
		ans = 0;
	} 
	return 0;
} 
