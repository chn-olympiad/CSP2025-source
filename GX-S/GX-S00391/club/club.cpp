#include <bits/stdc++.h>
#define f(i, s, e) for (int i = s; i <= e; i++)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
int a[N][3], T;
struct node{
	int val, id;
}b[N], c[N];
bool cmp(node a, node b){
	return a.val > b.val;
}
int main(){
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	cin >> T;
	while (T--){
		int ans1 = 0, ans2 = 0, n, is20 = 1;
		cin >> n;
		memset(a, 0, sizeof(a));
		f(i, 1, n){
			int Tempestissimo = -inf;
			b[i].id = i;
			f(j, 1, 3) cin >> a[i][j];
			if (is20 && a[i][2]) is20 = 0;
			Tempestissimo = max(max(max(Tempestissimo, a[i][1]), a[i][2]), a[i][3]);
			if (is20) b[i].val = Tempestissimo;
			ans1 += Tempestissimo;
		}
		if (is20){
			sort(b + 1, b + n + 1, cmp);
			f(i, 1, n / 2) ans2 += b[i].val;
			cout << ans2 << endl;
		}
		else cout << ans1 << endl;
	}
	return 0;
}
