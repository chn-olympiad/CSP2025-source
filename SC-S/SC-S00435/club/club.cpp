#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) (x) & (-x)
template<typename T> void read(T &x) {
	T f = 1; x = 0; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit((ch))) {x = x * 10 + ch - 48; ch = getchar();}
	x *= f;
}
const int N = 1e5 + 5;
int t, n, cnt[4], tmp[N];
struct stu{
	int w[4], mx, vis;
}a[N];
bool cmp(stu x, stu y) {
	return x.mx > y.mx;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	read(t);
	while(t--) {
		read(n);
		int up = n / 2;
		ll ans = 0;
		memset(cnt, 0, sizeof cnt);
		memset(tmp, 0, sizeof tmp);
		for(int i = 1; i <= n; i++) a[i].vis = a[i].mx = 0;
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <= 3; j++)
				read(a[i].w[j]);
		for(int i = 1; i <= n; i++) {
			a[i].mx = max(a[i].w[1], max(a[i].w[2], a[i].w[3]));
			if(a[i].w[1] == a[i].mx) a[i].vis = 1;
			else if(a[i].w[2] == a[i].mx) a[i].vis = 2;
			else a[i].vis = 3;
		}
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; i++) {
			cnt[a[i].vis]++;
			ans += a[i].mx;
		}
		if(cnt[1] <= up && cnt[2] <= up && cnt[3] <= up) printf("%lld\n", ans);
		else {
			int del, tot = 0;
			if(cnt[1] > up) {
				del = cnt[1] - up;
				for(int i = 1; i <= n; i++) 
					if(a[i].vis == 1) tmp[++tot] = a[i].w[1] - max(a[i].w[2], a[i].w[3]);
			}
			else if(cnt[2] > up) {
				del = cnt[2] - up;
				for(int i = 1; i <= n; i++) 
					if(a[i].vis == 2) tmp[++tot] = a[i].w[2] - max(a[i].w[1], a[i].w[3]);
			}
			else if(cnt[3] > up) {
				del = cnt[3] - up;
				for(int i = 1; i <= n; i++) 
					if(a[i].vis == 3) tmp[++tot] = a[i].w[3] - max(a[i].w[1], a[i].w[2]);
			}
			sort(tmp + 1, tmp + tot + 1);
			for(int i = 1; i <= del; i++) ans -= tmp[i];
			printf("%lld\n", ans);
		}		
	}
	return 0;
}