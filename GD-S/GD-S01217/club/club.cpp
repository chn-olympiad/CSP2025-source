#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define inl inline
#define rep(i,l,r) for(ri i = l;i <= r; i ++)
#define per(i,r,l) for(ri i = r;i >= l; i --)
#define N 100005
int T, n, vis[5];
struct ke{
	int d, id;
}a[4];
struct ss{
	int aa[4];
	ke A[4];
	int yr, ys;
}t[N];
inl bool cmp(ke x, ke y){
	return x.d > y.d;
}
inl bool cmp_1(ss x, ss y){
	if(x.yr != y.yr) return x.yr > y.yr;
	if(x.ys != y.ys) return x.ys > y.ys;
	if(x.aa[1] != y.aa[1]) return x.aa[1] > y.aa[1];
	if(x.aa[2] != y.aa[2]) return x.aa[2] > y.aa[2];
	if(x.aa[3] != y.aa[3]) return x.aa[3] > y.aa[3];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T --){
		cin >> n;
		rep(i, 0, 4) vis[i] = 0;
		rep(i, 1, n){
			cin >> a[1].d >> a[2].d >> a[3].d;
			a[1].id = 1, a[2].id = 2, a[3].id = 3;
			sort(a + 1, a + 4, cmp);
			t[i].yr = a[1].d - a[2].d;
			t[i].ys = a[1].d - a[3].d;
			rep(j, 1, 3){
				t[i].aa[a[j].id] = a[j].d;
				t[i].A[j] = a[j];
			}
		}
		sort(t + 1, t + 1 + n, cmp_1);
		int ans = 0;
		rep(i, 1, n){
			rep(j, 1, 3){
				int id = t[i].A[j].id;
				if(vis[id] < (n >> 1)){
					vis[id] ++;
					ans += t[i].A[j].d;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

