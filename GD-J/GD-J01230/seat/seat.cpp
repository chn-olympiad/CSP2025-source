#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],now,s[15][15],anum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n >> m;
	cin >> anum;
	a[1] = anum;
	for (int i = 2;i <= n * m;i++)
		cin >> a[i];
	sort(a + 1,a + n * m + 1);
	now = n * m;
	for (int j = 1;j <= m;j++){
		if (j % 2)
			for (int i = 1;i <= n;i++)
				s[i][j] = a[now--];
		else
			for (int i = 1;i <= n;i++)
				s[n - i + 1][j] = a[now--];
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (s[i][j] == anum)
				cout << i << " " << j;
	return 0;
}
