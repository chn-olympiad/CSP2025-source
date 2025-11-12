#include<bits/stdc++.h>
using namespace std;
int h, w, a[1010], R, id, ans;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w;
	for(int i = 1;i <= h * w;i ++) cin >> a[i];
	R = a[1];
	sort(a + 1, a + h * w + 1, cmp);
	for(int i = 1;i <= h * w;i ++) if(a[i] == R) id = i;
	ans = id / h;
	id -= ans * h;
	if(id > 0) ans ++;
	if(id == 0) id = h;
	if(ans % 2 == 0) cout << ans << " " << h - id + 1;
	else if(ans % 2 == 1) cout << ans << " " << id;
}
