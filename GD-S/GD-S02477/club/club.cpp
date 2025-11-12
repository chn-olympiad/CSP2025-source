#include<bits/stdc++.h>
namespace kimi{
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb emplace_back
#define endl '\n'
#define dbg(x) cerr << x << endl
#define TLE AC
#define WA AC
using namespace std;
const int maxn = 1e5 + 10;
struct node{
	int a, b, c;
	int ch;
}A[maxn];
int n;
int ans;
void mian(){
	ans = 0;
	cin >> n;
	int x = 0, y = 0, z = 0;
	for(int i = 1; i <= n; i++){
		cin >> A[i].a >> A[i].b >> A[i].c;
		int mx = max({A[i].a, A[i].b, A[i].c});
		if(mx == A[i].a){
			ans += mx;
			x++;
			A[i].ch = 1;
		}else if(mx == A[i].b){
			ans += mx;
			y++;
			A[i].ch = 2;	
		}else if(mx == A[i].c){
			ans += mx;
			z++;
			A[i].ch = 3;	
		}
	}
	vector<node> B;
	if(x > n / 2){
		for(int i = 1; i <= n; i++){
			if(A[i].ch == 1) B.pb(A[i]);
		}
		sort(B.begin(), B.end(), [](node x, node y){return x.a - max(x.b, x.c) < y.a - max(y.b, y.c);});
		for(auto b : B){
			if(x == n / 2) break;
			int mx = max(b.b, b.c);
			ans += mx - b.a;
			x--;
			if(mx == b.b) y++;
			else z++;
		}
	}
	if(y > n / 2){
		for(int i = 1; i <= n; i++){
			if(A[i].ch == 2) B.pb(A[i]);
		}
		sort(B.begin(), B.end(), [](node x, node y){return x.b - max(x.a, x.c) < y.b - max(y.a, y.c);});
		for(auto b : B){
			if(y == n / 2) break;
			int mx = max(b.a, b.c);
			ans += mx - b.b;
			y--;
			if(mx == b.a) x++;
			else z++;
		}
	}
	if(z > n / 2){
		for(int i = 1; i <= n; i++){
			if(A[i].ch == 3) B.pb(A[i]);
		}
		sort(B.begin(), B.end(), [](node x, node y){return x.c - max(x.a, x.b) < y.c - max(y.a, y.b);});
		for(auto b : B){
			if(z == n / 2) break;
			int mx = max(b.a, b.b);
			ans += mx - b.c;
			z--;
			if(mx == b.a) x++;
			else y++;
		}
	}
	cout << ans << endl;
}
}using namespace kimi;
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int Test = 1;
	cin >> Test;
	while(Test--) mian();
	return 0;
}
/*
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
