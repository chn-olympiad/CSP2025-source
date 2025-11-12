#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N (int)(1e5 + 5)
#define M (int)(1e6 + 5)
#define mod (int)(1e9 + 7)
#define inf (int)(2e9)
#define qwe(i, l, r) for(int i = l; i <= r; i++)
#define ewq(i, r, l) for(int i = r; i >= l; i--)
#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int T = 1;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		f = ch =='-' ? -f : f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, ans;
int a[N][4], maxx[N][4];
int cost(int id){return a[id][maxx[id][1]] - a[id][maxx[id][2]];}
void solve(){
	n = read();
	ans = 0;
	priority_queue<P, vector<P>, greater<P> >q[4];
	qwe(i, 1, n){
		a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
		int mx = max({a[i][1], a[i][2], a[i][3]});
		if(mx == a[i][1]){
			maxx[i][1] = 1;
			if(a[i][2] > a[i][3]) maxx[i][2] = 2, maxx[i][3] = 3;
			else maxx[i][2] = 3, maxx[i][3] = 2;
		}
		else if(mx == a[i][2]){
			maxx[i][1] = 2;
			if(a[i][1] > a[i][3]) maxx[i][2] = 1, maxx[i][3] = 3;
			else maxx[i][2] = 3, maxx[i][3] = 1;
		}
		else {
			maxx[i][1] = 3;
			if(a[i][1] > a[i][2]) maxx[i][2] = 1, maxx[i][3] = 2;
			else maxx[i][2] = 2, maxx[i][3] = 1;
		}
	}
	qwe(i, 1, n){
		if(q[maxx[i][1]].size() < n / 2){
			q[maxx[i][1]].push(MP(cost(i), i));
			ans += a[i][maxx[i][1]];
		}
		else{
			P t = q[maxx[i][1]].top();
			if(cost(t.se) > cost(i)){
				q[maxx[i][2]].push(MP(cost(i), i));
				ans += a[i][maxx[i][2]];
			}
			else{
				q[maxx[i][1]].pop();
				q[maxx[i][1]].push(MP(cost(i), i));
				q[maxx[t.se][2]].push(t);
				ans += a[i][maxx[i][1]] - cost(t.se);
			}
		}
	}
	printf("%d\n", ans);
}
int main(){
//	freopen("club.ans", "r", stdout);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T--) solve();
	return 0;
}
/*
2
0 1 0
0 1 0
0 2 0
0 2 0

Makka pakka :D
*/
