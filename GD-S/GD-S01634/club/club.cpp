#include <bits/stdc++.h>
using namespace std;
struct s{
	int x,y,z;
} a[100005];
int t,n,ans;
bool cmp(s i,s j){
	return i.x > j.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y >> a[i].z;
		if (n == 2){
			ans = max(ans,a[1].x + a[2].y);
			ans = max(ans,a[1].x + a[2].z);
			ans = max(ans,a[1].y + a[2].x);
			ans = max(ans,a[1].y + a[2].z);
			ans = max(ans,a[1].z + a[2].x);
			ans = max(ans,a[1].z + a[2].y);
			cout << ans << endl;
			continue;
		}
		sort(a + 1,a + n + 1,cmp);
		for (int i = 1;i <= n / 2;i++) ans += a[i].x;
		cout << ans << endl;
	}
	return 0;
}
//f[i][j] = max(f[i][j - 1] + f[~i][j - 1])
