#include <bits/stdc++.h>
using namespace std;

int n,a[5005],z[5005],ans;
bool t[5005];

void dfs(int b,int pos,int s) {
	if (b == pos - 1) {
		int sum = 0,maxn = 0;
		for (int i = 1;i <= pos - 1;i++) {
			maxn = max(maxn,z[i]);
			sum += z[i];
		}
		if (sum > maxn * 2) {
			ans++;
			ans %= 998244353;
		}
		return ;
	}
	for (int i = s;i <= n;i++) {
		if (t[i] == false) {
			z[pos] = a[i];
			t[i] = true;
			dfs(b,pos + 1,i);
			t[i] = false;
		}
	}
}

int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 3;i <= n;i++) {
		dfs(i,1,1);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
