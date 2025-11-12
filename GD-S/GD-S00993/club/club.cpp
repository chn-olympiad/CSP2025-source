#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
struct node{
	int a, b, c;
	int fav;
	int ab, bc, ca;
}a[N];
bool cmp1(node n, node m){ return min(n.ab, -n.ca) < min(m.ab, -m.ca); }
bool cmp2(node n, node m){ return min(-n.ab, n.bc) < min(-m.ab, m.bc); }
bool cmp3(node n, node m){ return min(-n.bc, n.ca) < min(-m.bc, m.ca); }
void solve(){
	int n; scanf("%d",&n);
	int x, y, z;
	x = y = z = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		a[i].ab = a[i].a - a[i].b, a[i].bc = a[i].b - a[i].c, a[i].ca = a[i].c - a[i].a;
		if(a[i].ab >= 0 && a[i].ca < 0) x++, a[i].fav = 1;
		if(a[i].ab < 0 && a[i].bc >= 0) y++, a[i].fav = 2;
		if(a[i].ca >= 0 && a[i].bc < 0) z++, a[i].fav = 3;
	}
	if(x <= n/2 && y <= n/2 && z <= n/2){
		int ans = 0; 
		for(int i = 1; i <= n; i++){
			if(a[i].fav == 1) ans += a[i].a;
			if(a[i].fav == 2) ans += a[i].b;
			if(a[i].fav == 3) ans += a[i].c;
		}
		printf("%d\n",ans);
		return ;
	} else {
		int ans = 0;
		if(x > n/2){
			sort(a + 1, a + n + 1, cmp1);
			for(int i = 1; i <= n/2; i++) ans += max(a[i].b, a[i].c);
			for(int i = n/2+1; i <= n; i++) ans += a[i].a;
		} else if(y > n/2){
			sort(a + 1, a + n + 1, cmp2);
			for(int i = 1; i <= n/2; i++) ans += max(a[i].a, a[i].c);
			for(int i = n/2+1; i <= n; i++) ans += a[i].b;
		} else {
			sort(a + 1, a + n + 1, cmp3);
			for(int i = 1; i <= n/2; i++) ans += max(a[i].b, a[i].a);
			for(int i = n/2+1; i <= n; i++) ans += a[i].c;
		}
		printf("%d\n",ans);
		return ;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}
