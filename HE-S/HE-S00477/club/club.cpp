#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int a[maxn][3], l1 = 1, l2 = 1, l3 = 1;
int n, hn, f[maxn][3]; 

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	for (int ttt = 1;ttt <= T;++ttt){
		memset(f, 0, sizeof(f));
		cin >> n;
		hn = n / 2;
		for (int i = 1;i <= n;++i){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		f[1][0] = a[1][0];
		f[1][1] = a[1][1];
		f[1][2] = a[1][2];
		int m = 0, p = 0;
		for (int j = 0;j <= 2;++j){
			if (f[1][j] > m){
				m = f[1][j];
				p = j;
			}
		}
		for (int i = 2;i <= n;++i){
			for (int j = 0;j <= 2;++j){
				if (j == 0 && l1 > hn) continue;
				if (j == 1 && l2 > hn) continue;
				if (j == 2 && l3 > hn) continue;
				f[i][j] = m + a[i][j]; 
			}
			if (p == 0) l1++;
			if (p == 1) l2++;
			if (p == 2) l3++;
			for (int j = 0;j <= 2;++j){
				if (f[i][j] > m){
					m = f[i][j];
					p = j;
				}
			}
		}
		cout << max(max(f[n][1], f[n][2]), max(f[n][2], f[n][0])) << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
