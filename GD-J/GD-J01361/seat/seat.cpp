#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define inl inline
#define rep(i,l,r) for(ri i = l; i <= r; i ++)
#define per(i,r,l) for(ri i = r; i >= l; i ++)
#define N 1005
int n, m;
int a[N];
inl bool cmp(int x, int y){
	return x > y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	rep(i, 1, n * m) cin >> a[i];
	int t = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	int l = 1, r = 1, cur = a[1], row = 1, tot = 1;
	while(1){
		if(cur == t){
			cout << r << " " << l;
			return 0;
		}
		if(row % 2){
			l ++;
		}
		else{
			l --;
		}
		if(l == n + 1){
			l = n;
			r ++;
			row = 1 - row; 
		}
		else if(l == 0){
			l = 1;
			row = 1 - row;
			r ++;
		}
		cur = a[++ tot];
//		cout << l << " " << r << " " << cur << endl;
	}
	return 0;
}

