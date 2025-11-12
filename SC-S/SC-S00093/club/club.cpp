#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

#define int long long

int w[200005][4];
int t, n, flagA, flagB; 
int ans;
int p[4];
int a[200005];
struct dx{
	int max1,max2, i;
	int maxi1, maxi2;
}b[200005];
bool cmp(dx x, dx y) {
	if (x.max1 - x.max2 == y.max1 - y.max2) return x.max1 > y.max2;
	return x.max1 - x.max2 > y.max1 - y.max2;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		flagA = flagB = ans = p[1] = p[2] = p[3] = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[1] >> a[2] >> a[3];
			w[i][1] = a[1],w[i][2] = a[2],w[i][3] = a[3];
			sort(a + 1, a + 4);
			b[i].max1 = a[3];
			b[i].max2 = a[2];
			b[i].i = i;
			for(int j = 1; j <= 3; ++j) {
				if(w[i][j] == b[i].max1){
					b[i].maxi1 = j;
				} else if(w[i][j] == b[i].max2){
					b[i].maxi2 = j;
				}
			}
		}
		sort(b + 1, b + n + 1, cmp);
		for(int i = 1; i <= n; ++i) {
			int ii = b[i].i;
			if(p[b[i].maxi1] < n / 2) {
				p[b[i].maxi1]++;
				ans += b[i].max1;
			}else if(p[b[i].maxi2] < n / 2){
				p[b[i].maxi2]++;
				ans += b[i].max2;
			}else{
				p[6 - b[i].maxi1 -b[i].maxi2]++;
				ans += w[ii][6 - b[i].maxi1 -b[i].maxi2];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
