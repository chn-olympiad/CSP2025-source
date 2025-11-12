#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define inl inline
#define rep(i,l,r) for(ri i = l;i <= r; i ++)
#define per(i,r,l) for(ri i = r;i >= l; i --)
#define N 2005
int n, q;
string s1[N], s2[N];
int ls[N];
int nx[N][N];
inl void init(int id){
	nx[id][1] = 0;
	for(ri i = 2, j = 0; i <= ls[id]; i ++){
		while(j && s1[id][i] != s1[id][j + 1]) j = nx[id][j];
		if(s1[id][i] == s1[id][j + 1]) j ++;
		nx[id][i] = j;
	}
}
string x[N], z[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	rep(i, 1, n) cin >> s1[i] >> s2[i], ls[i] = s1[i].size();
	rep(i, 1, n){
		s1[i] = ' ' + s1[i];
		init(i);
	}
	string t1, t2;
	while(q --){
		cin >> t1 >> t2;
		int lt = t1.size(), ans = 0;;
		t1 = ' ' + t1;
		rep(i, 1, lt){
			x[i] = x[i - 1] + t1[i];
		}
		per(i, lt, 1){
			z[i] = z[i + 1] + t1[i];
		}
//		rep(i, 1, lt) cout << x[i] << endl;
		rep(id, 1, n){
			for(ri i = 1, j = 0; i <= lt; i ++){
				while(j && t1[i] != s1[id][j + 1]) j = nx[id][j];
				if(t1[i] == s1[id][j + 1]) j ++;
				if(j == ls[id]){
//					cout <<id << " "<< i - ls[id] + 1<< endl;
					if(x[i - ls[id]] + s2[id] + z[i + 1] == t2) ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
