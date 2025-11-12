#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 7;

struct Node{
	long long a1, a2, a3;
};
int t;
int n;
Node a[Nmax];
long long ans;
int num;

bool cmp(const Node p1, const Node p2){
	if(p1.a1 == p2.a1){
		if(p1.a2 == p2.a2)
			return p1.a3 >= p2.a3;
		return p1.a2 >= p2.a2;
	}
	return p1.a3 >= p2.a3;
}

void DFS(int p, int c1, int c2, int c3, long long sum){
	if(p > n){
		ans = max(ans, sum);
		return;
	}
	if(c1 < num)
		DFS(p + 1, c1 + 1, c2, c3, sum + a[p].a1);
	if(c2 < num)
		DFS(p + 1, c1, c2 + 1, c3, sum + a[p].a2);
	if(c3 < num)
		DFS(p + 1, c1, c2, c3 + 1, sum + a[p].a3);
}

void solve(){
	ans = 0;
	cin >> n;
	num = n / 2;
	for(int i = 1;i <= n;i++)
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
	sort(a + 1, a + n + 1, cmp);
	DFS(1, 0, 0, 0, 0);
	cout << ans << endl;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
		solve();
	return 0;
}