#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for1(i,a,b) for(ll i=a;i<=b;++i)
#define for0(i,a,b) for(ll i=a;i>=b;--i)
const ll N = 1e5+10, M = 0;
const ll MOD = 0;
ll t, n, a[N][5], l[5], cnt[5], ans; 
struct st{
	ll c1, c2, bh;
	bool operator < (st temp) const {
		if (c1 == temp.c1)	return c2 > temp.c2;
		return c1 > temp.c1; 
	}
}b[N];
struct sp{
	ll z, bh;
	bool operator < (sp tem) const {
		return z > tem.z;
	}
}p[5];
signed main (){
  freopen ("club.in", "r", stdin);
  freopen ("club.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >>t; ++ t;
	while (-- t){
		cin >>n; ans = 0;
		for1 (i, 1, n){
			cin >>a[i][1] >>a[i][2] >>a[i][3];
			l[1] = a[i][1], l[2] = a[i][2], l[3] = a[i][3];
			sort (l+1, l+4);
			b[i].c1 = l[3]-l[2];
			b[i].c2 = l[2]-l[1];
			b[i].bh = i;
		}
		sort (b+1, b+n+1);
		cnt[1] = cnt[2] = cnt[3] = 0;
		for1 (_i, 1, n){
			ll i =  b[_i].bh;
			ll maxx, mcxx, minn;
			for1 (j, 1, 3) {p[j] = {a[i][j], j};}
			sort (p+1, p+4);
			maxx = p[1].bh, mcxx = p[2].bh, minn = p[3].bh;
			if (cnt[maxx]+1 <= n/2){
				++ cnt[maxx];
				ans += a[i][maxx];
				continue;
			}
			++ cnt[mcxx];
			ans += a[i][mcxx];
		}
		cout <<ans <<"\n";
	}
	return 0;
}
/*
3
4 4 2 1 3 2 4 5 3 4 3 5 1
4 0 1 0 0 1 0 0 2 0 0 2 0
2 10 9 8 4 0 0
*/
// 100 pts
