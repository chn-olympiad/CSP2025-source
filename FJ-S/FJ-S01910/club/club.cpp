#include <bits/stdc++.h>
using namespace std;

int cb[4][100010];
int f[4][100010];
int cnt[4];
struct node {
	int id, g;
};
node minn[4][100010];
bool cmp(node x, node y)
{
	return x.g < y.g;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		memset(f, -1, sizeof(f));
		memset(cb, 0, sizeof(cb));
		memset(minn, 0, sizeof(minn));
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		for(int i = 1; i<=n; i++) {
			cin >> cb[1][i] >> cb[2][i] >> cb[3][i];
			minn[1][i].g = cb[1][i] - cb[2][i];
			minn[2][i].g = cb[2][i] - cb[3][i];
			minn[3][i].g = cb[3][i] - cb[1][i];
			minn[1][i].id = minn[2][i].id = minn[3][i].id = i;
			int maxi = 0;
			if(cb[1][i] > cb[2][i]) {
				if(cb[1][i] > cb[3][i]) {
					maxi = 1;
				} else {
					maxi = 3;
				}
			} else if(cb[2][i] > cb[3][i]) {
				maxi = 2;
			} else {
				maxi = 3;
			}
			f[maxi][i] = maxi;
			cnt[maxi]++;
		}
		for(int i = 1; i<=3; i++) {
			sort(minn[i]+1, minn[i]+n+1, cmp);
//			cout << "It's" << i << endl;
//			for(int l = 1; l<=n; l++) {
//				for(int k = 1; k<=3; k++) cout << minn[k][l].id <<" " << minn[k][l].g <<"  ";
//				cout << endl;
//			}
//			cout << endl;
			if(cnt[i] > n/2) {
				for(int j = 1; j<=n; j++) {
					int less = i-1;
					if(less == 0) less = 3;
					int more = i+1;
					if(more == 4) more = 1;
					if(f[i][minn[i][j].id] == -1 or minn[i][j].g < 0 or minn[less][j].g > 0) continue;
//					cout << "We are coming in " << i << " " << minn[i][j].id << endl;
					cnt[i]--;
					if(minn[i][j].g > -minn[less][j].g) {
//						cout << "We chose " << more << endl;
						f[less][minn[i][j].id] = more;
						cnt[more]++;
					} else {
//						cout << "We chose " << less << endl;
						f[more][minn[i][j].id] = less;
						cnt[less]++;
					}
					f[i][minn[i][j].id] = -1;
//					cout <<"less of"<< cnt[i] << endl;
					if(cnt[i] <= n/2) break;
				}
			}
		}
		int ans = 0;
		for(int j = 1; j<=n; j++) {
			for(int i = 1; i<=3; i++) {
				if(f[i][j] != -1) {
					ans += cb[i][j];
//					cout << "We chose the" << i <<",hopes are" << cb[i][j] << endl;
					break;
				}
			}
		}
		cout /*<<"The answer is:"*/<< ans << endl;
	}
	return 0;
}
