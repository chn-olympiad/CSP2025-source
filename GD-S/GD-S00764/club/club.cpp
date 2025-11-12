#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int t, n, x[N], y[N], z[N], tx, ty, tz;
struct stu{
	int a[4], ma, km;
}s[N];
void solve(){
	long long sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i].a[1] >> s[i].a[2] >> s[i].a[3];
		s[i].ma = max(max(s[i].a[1], s[i].a[2]), s[i].a[3]);
		if(s[i].ma = s[i].a[1]) s[i].km = 1;
		if(s[i].ma = s[i].a[2]) s[i].km = 2;
		if(s[i].ma = s[i].a[3]) s[i].km = 3;
		if(s[i].km = 1) x[++tx] = s[i].ma;
		if(s[i].km = 2) x[++ty] = s[i].ma;
		if(s[i].km = 3) x[++tz] = s[i].ma;
	}
	sort(x + 1, x + tx + 1);
	sort(y + 1, y + ty + 1);
	sort(z + 1, z + tz + 1);
	if(tx <= n / 2){
		for(int i = 1; i <= tx; i++) sum += x[i];
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
} 
