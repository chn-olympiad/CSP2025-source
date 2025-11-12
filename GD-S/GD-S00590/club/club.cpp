#include <bits/stdc++.h>
using namespace std;
#define int long long
struct tr{
	int x, y, z;
}a[100005];

bool cmp(tr c, tr b){
	return max(c.x, max(c.y, c.z)) > max(b.x, max(b.y, b.z));
}

signed main(){

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
		sort(a + 1, a + n + 1, cmp);
		
		int ma = n/2;
		int xc = 0, yc = 0, zc = 0, ans = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i].x > a[i].y){
				if(a[i].y >= a[i].z){
					if(xc <= ma){
						ans += a[i].x;
						xc++;
						continue;
					}
					if(a[i].y > a[i].z){
						if(yc <= ma){
							ans += a[i].y;
							yc++;
							continue;
						}
					}
					else if(yc < zc){
						ans += a[i].y;
						yc++;
						continue;
					}
				}
			}
			else if(a[i].x >= a[i].z){
				if(a[i].y > a[i].x){
					if(yc <= ma){
						ans += a[i].y;
						yc++;
						continue;
					}
					if(a[i].x > a[i].z){
						if(xc <= ma){
							ans += a[i].x;
							xc++;
							continue;
						}
					}
					else if(xc < zc){
						ans += a[i].x;
						xc++;
						continue;
					}
				}
			}
			ans += a[i].z;
			zc++;
			continue;
		}
		cout << ans;
	}
	
	return 0;
} 
