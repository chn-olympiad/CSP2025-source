#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T>inline void read(T &x){
	char c;int sign = 1;x = 0;
	do{c = getchar();if (c == '-') sign = -1;}while (! isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();} while (isdigit(c));
	x *= sign;
}
template <typename T>inline void wr(T x){
	if (x < 0){putchar('-');x = -x;}
	if (x > 9) wr(x / 10);
	putchar((x % 10) | 48);
}

const int N = 1e5 + 5;
int T;
int n,a[N][4],ans,c[N];
struct node{
	int b,id;
}p[N];
bool f[N];
/*
2211746
2527345
2706385
2710832
2861471

147325
125440
152929
150176
158541

447450
417649
473417
443896
484387

1499392690
1500160377
1499846353
1499268379
1500579370

*/
inline bool cmp(node x,node y){return x.b > y.b;}
inline bool cmp2(int x,int y){return x > y;}
inline void solve(){
	read(n);
	ans = 0;
	memset(f,0,sizeof f);
	for ( int i = 1; i <= n; i ++){
		for ( int j = 1; j <= 3; j ++){
			read(a[i][j]);
		}
	}
	for ( int i = 1; i <= n; i ++){
		p[i].b = a[i][2] - a[i][1];
		p[i].id = i;
	}
	sort(p + 1,p + n + 1,cmp);
	for ( int i = 1; i <= n; i ++){
		ans += a[i][1];
	}
	for ( int i = 1; i <= n / 2; i ++){
		ans += p[i].b;
		f[p[i].id] = 1;
	}
	for ( int i = 1; i <= n; i ++){
		if (f[i]){
			if (p[i].b <= 0){
				c[i] = max(a[i][3] - a[i][2], a[i][3] - a[i][1]);
			}else c[i] = a[i][3] - a[i][2];
		}else {
			if (p[i].b > 0){
				c[i] = max(a[i][3] - a[i][2], a[i][3] - a[i][1]);
			}else c[i] = a[i][3] - a[i][1];
			
		}
			
	}
	sort(c + 1,c + n + 1,cmp2);
	for ( int i = 1; i <= n / 2; i ++){
		if (c[i] <= 0) break;
		ans += c[i];
	}
	wr(ans);putchar('\n');
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	// T = 1;
	while (T --){
		solve();
	}
	
	return 0;
}
