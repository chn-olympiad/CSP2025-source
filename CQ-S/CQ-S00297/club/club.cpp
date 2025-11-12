#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define intl long long
#define inf 0x7fffffff
#define For(i,a,b) for(intl i = a;i <= b;i ++)
#define deo(i,a,b) for(intl i = a;i >= b;i --)
intl read() {
	intl x = 0, k = 1;char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') k = -1; ch = getchar();}
	while(isdigit(ch)) x = (x<<3) + (x<<1) + (ch - '0'), ch=getchar();
	return x*k;
}
intl n;
intl a[N][10], b[N][10], d[N], mx[N], md[N], mn[N], p[N];
set<pair<intl,intl>> st[10];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	intl T = read();
	while(T--) {
		n = read();
		intl ans = 0;
		For(i,1,n) {
			mx[i] = -1, mn[i] = inf;
			For(j,1,3) a[i][j] = read(), mx[i] = max(mx[i],a[i][j]), mn[i] = min(mn[i],a[i][j]);
			md[i] = a[i][1] + a[i][2] + a[i][3] - mx[i] - mn[i];
			For(j,1,3) if(a[i][j] == mx[i]) b[i][1] = j;
			For(j,1,3) if(a[i][j] == md[i] && b[i][1] != j) b[i][2] = j;
			d[i] = mx[i] - md[i], p[i] = md[i] - mn[i];
			ans += mx[i];
			st[b[i][1]].insert({d[i],i});
		}
		For(i,1,3) while(st[i].size() > n/2) ans -= st[i].begin()->first, st[i].erase(st[i].begin());
		printf("%lld\n",ans);
		For(i,1,n) For(j,1,3) a[i][j] = b[i][j] = d[i] = mn[i] = mx[i] = md[i] = p[i] = 0; 
		For(i,1,3) st[i].clear();n = 0;
	}
	return 0;
}
/*

*/

