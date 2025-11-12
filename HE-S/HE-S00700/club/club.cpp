#include<bits/stdc++.h>
using namespace std;
int a[11110][11110];
int f[11110][11110];
int p[111110];
int cnt[11110];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >>t;
	for(int tt = 1; tt <= t; tt ++) {
		int n,ans = 0;
		cin >>n;
		int hn = n / 2;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) {
				cin >>a[i][j];
			}
		}
		
		//找最大值 
		for (int k = 1; k <= n; k ++) {
			int maxn = 0;
			int ti,tj;
			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j <= 3; j ++) {
					if(a[i][j] >= maxn && cnt[j] < hn) {
						maxn = a[i][j];
						ti = i;
						tj = j;
					}
				}
			}

			f[ti][tj] = a[ti][tj];
			a[ti][tj] = 0;
			cnt[tj] ++;
			for (int l = 1; l <= 3; l ++) {
				a[ti][l] = 0;
			}
			ti = 0,tj = 0,maxn = 0;


		}


		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= 3; j ++) {
				ans += f[i][j];
			}
		}
		cout <<ans<<endl;
		//最后一步所有数组初始化 
		for (int i = 1;i <= n;i ++){
			for (int j = 1;j <= 3;j ++){
				f[i][j] = 0;
			}
		}
		for (int i = 1;i <= 11110;i ++){
			cnt[i] = 0;
		} 

	}

	return 0;
}
