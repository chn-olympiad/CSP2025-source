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

const int N = 1e4 + 15,inf = LONG_LONG_MAX;
int T;
int n,m,k,tot,ans;
int pr[N],c[15];
inline int findl(int a){
	return a == pr[a] ? a : pr[a] = findl(pr[a]);
}
//int f[N][N];
struct node{
	int x,y,z;
	
	inline bool operator <(node a)const{
		return z < a.z;	
	}
}p[1100005];
map<int,int> ma;
/*

*/
inline void solve(){
	read(n);read(m);read(k);
	for ( int i = 1; i <= n + k; i ++) pr[i] = i; 
	for ( int i = 1; i <= m; i ++){
		int u,v,w;
		read(u);read(v);read(w);
		p[++ tot].x = u;
		p[tot].y = v;
		p[tot].z = w;
	}
	for ( int i = 1; i <= k; i ++){
		read(c[i]);
		for ( int j = 1; j <= n; j ++){
			int a;read(a);
			p[++ tot].x = n + i;
			p[tot].y = j;
			p[tot].z = a + c[i];
		}
	}
	sort(p + 1,p + tot + 1);
	if (k == 0){
		for ( int i = 1; i <= tot; i ++){
			int xr = findl(p[i].x);
			int yr = findl(p[i].y);
			if (xr != yr){
				ans += p[i].z;
				pr[yr] = xr;
//			wr(p[i].x);putchar(' ');wr(p[i].y);putchar(' ');wr(p[i].z);putchar('\n');
			}
		}	
	}else{
		for ( int i = 1; i <= tot; i ++){
			int xr = findl(p[i].x);
			int yr = findl(p[i].y);
			if (xr != yr){
				ans += p[i].z;
				pr[yr] = xr;
				if (p[i].x > n){
					ma[p[i].x - n] ++;	
				} 
				bool flag = 0;
				int root = findl(1);
				for ( int j = 2; j <= n; j ++){
					if (findl(j) != root){
						flag = 1;break;
					}
				}
				if (! flag){
					for ( int j = 1; j <= k; j ++){
						if (ma[j] > 0){
							ans -= (ma[j] - 1) * c[j];
						}
					}
					break;
				}
//			wr(p[i].x);putchar(' ');wr(p[i].y);putchar(' ');wr(p[i].z);putchar('\n');
			}
		}
	}
	
	wr(ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	T = 1;
	while (T --){
		solve();
	}

//	cout << log2(1000000);
	return 0;
}
