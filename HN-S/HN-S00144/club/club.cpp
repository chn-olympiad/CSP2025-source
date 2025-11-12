#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, t;
struct node{
	int x, y, z, maxn;
}a[100005];
signed main(){
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--){
		int x = 0, y = 0, z = 0, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].x > a[i].y){
				if (a[i].x > a[i].z){
					a[i].maxn = 1;
					x++;
				}
				else{
					z++;
					a[i].maxn = 3;
				}
			}
			else{
				if (a[i].y > a[i].z){
					y++;
					a[i].maxn = 2;
				}
				else{
					z++;
					a[i].maxn = 3;
				}
			}
		}
		for (int i = 1; i <= n; i++){
			if (a[i].maxn == 1){
				ans += a[i].x;
			}
			if (a[i].maxn == 2){
				ans += a[i].y;
			}
			if (a[i].maxn == 3){
				ans += a[i].z;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
