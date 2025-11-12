#include<bits/stdc++.h>
using namespace std;
#define _sortby(target, cmp) do{ \
	memcpy(sortby[target], a, sizeof(a)); \
	sort(sortby[target] + 1, sortby[target] + n + 1, cmp); \
}while(0);
int t;
int n;
struct dat{
	int id;
	int p[5];
};
dat a[100010];
dat sortby[10][100010];
int _mx(dat x){ return max(max(x.p[1], x.p[2]), x.p[3]); }
int _sm(dat x){ return x.p[1] + x.p[2] + x.p[3]; }
bool cmp1(dat a, dat b){ return a.p[1] < b.p[1]; }
bool cmp2(dat a, dat b){ return a.p[2] < b.p[2]; }
bool cmp3(dat a, dat b){ return a.p[3] < b.p[3]; }
bool cmpd1(dat a, dat b){ return _mx(a) - max(a.p[2], a.p[3]) < _mx(b) - max(b.p[2], b.p[3]); }
bool cmpd2(dat a, dat b){ return _mx(a) - max(a.p[1], a.p[3]) < _mx(b) - max(b.p[1], b.p[3]); }bool cmpd3(dat a, dat b){ return _mx(a) - max(a.p[1], a.p[2]) < _mx(b) - max(b.p[1], b.p[2]); }

int to[100010], cnt[5];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --){
		cin >> n;
		for(int i = 1; i <= n; i ++){
			a[i].id = i;
			for(int j = 1; j <= 3; j ++) cin >> a[i].p[j];
		}
		_sortby(1, cmp1);
		_sortby(2, cmp2);
		_sortby(3, cmp3);
		_sortby(4, cmpd1);
		_sortby(5, cmpd2);
		_sortby(6, cmpd3);
		memset(to, 0, sizeof(to));
		memset(cnt, 0, sizeof(cnt));
		cnt[0] = n;
		for(int i = 1; i <= 3; i ++){
			for(int j = 1; j <= n; j ++){
				if(a[j].p[to[j]] < a[j].p[i]){
					cnt[to[j]] --; cnt[i] ++;
					to[j] = i;
				}
			}
		}
		int over = -1;
		for(int i = 1; i <= 3; i ++) if(cnt[i] > n / 2) over = i;
		if(over == -1){
			int ans = 0;
			for(int i = 1; i <= n; i ++) ans += a[i].p[to[i]];
			cout << ans << endl;
			continue;
		}
		for(int i = 1; i <= n; i ++){
			int id = sortby[over + 3][i].id;
			if(cnt[over] <= n / 2) break;
			if(to[id] != over) continue;
			to[id] = 0; cnt[over] --;
			int mx = 0;
			for(int j = 1; j <= 3; j ++){
				if(j == over) continue;
				if(a[id].p[j] > a[id].p[mx]) mx = j;
			}
			to[id] = mx; cnt[mx] ++;
		}
		int ans = 0;
		for(int i = 1; i <= n; i ++) ans += a[i].p[to[i]];
		cout << ans << endl;
	}
}