#include<bits/stdc++.h>
using namespace std;
int n, ans;
int st[5005];
int v[5005];
bool flag;

void dfs(int b, int k, int num, int ma, int la)
{
	if(k >= b) {
		if(num > 2 * ma) ans++;
		return ;
	}
	for(int i = la + 1 ; i <= n ; i++) {
		if(!v[i]) {
			v[i] = 1;
			dfs(b, k + 1, num + st[i], max(ma, st[i]), i);
			v[i] = 0;
		}
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> st[i];
	}
	for(int i = 3 ; i <= n ; i++) {
		memset(v, 0, sizeof(v));
		dfs(i, 0, 0, 0, 0);
	}
	cout << ans;
}

