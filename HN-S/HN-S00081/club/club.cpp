#include<bits/stdc++.h>
using namespace std;
struct ap{
	int a1, a2, a3;
}a[100005];
bool cmp(ap a, ap b){
	if (a.a1 == b.a1){
		if (a.a2 == b.a2)
			return a.a3 > b.a3;
		return a.a2 > b.a2;
	}
	return a.a1 > b.a1;
}
int t, n, f[100005][4][4];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		cin >> n;
		for (int i = 1; i <= n; i++){
			f[i][1][0] = -1;
			f[i][2][0] = -1;
			f[i][3][0] = -1;
		}
		for (int i = 1; i <= n; i++)
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		sort(a + 1, a + n + 1, cmp);
		/*
		for (int i = 1; i <= n; i++)
			cout << a[i].a1 << " " << a[i].a2 << " " << a[i].a3 << endl;
			*/
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++){
				int as;
				if (j == 1)
					as = a[i].a1;
				if (j == 2)
					as = a[i].a2;
				if (j == 3)
					as = a[i].a3;
				for (int k = 1; k <= 3; k++)
					if (f[i - 1][k][j] + 1 <= n / 2){
						//cout << i << " " << j << " " << k << endl;
						if (f[i - 1][k][0] + as > f[i][j][0]){
							f[i][j][0] = max(f[i][j][0], f[i - 1][k][0] + as);
							f[i][j][1] = f[i - 1][k][1];
							f[i][j][2] = f[i - 1][k][2];
							f[i][j][3] = f[i - 1][k][3];
							f[i][j][j] = f[i - 1][k][j] + 1;
						}
						/*
						cout << f[i][j][0] << " ";
						cout << f[i][j][1] << " ";
						cout << f[i][j][2] << " ";
						cout << f[i][j][3] << endl << endl;
						*/
					}
				}
		int maxn = 0;
		for (int i = 1; i <= 3; i++)
			maxn = max(maxn, f[n][i][0]);
		cout << maxn << endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
} 
