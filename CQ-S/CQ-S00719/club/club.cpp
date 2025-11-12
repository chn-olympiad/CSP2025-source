#include<cstdio>
#include<cstring>
using namespace std;
int const N = 1e5 + 1;
int seq[3][N], to[3][N], to2[N], cnt[3], t, n, ans, sgg[2][N], sggl;
void push_down(int n) {
	for(int i = n;i * 2 < sggl;) {
		if(i * 2 + 1 >= sggl) {
			int tmp;
			tmp = sgg[1][i * 2], sgg[1][i * 2] = sgg[1][i], sgg[1][i] = tmp;
			tmp = sgg[0][i * 2], sgg[0][i * 2] = sgg[0][i], sgg[0][i] = tmp;
			i *= 2;
			continue;
		}
		if(sgg[1][i * 2] < sgg[1][i * 2 + 1]) {
			int tmp;
			tmp = sgg[1][i * 2], sgg[1][i * 2] = sgg[1][i], sgg[1][i] = tmp;
			tmp = sgg[0][i * 2], sgg[0][i * 2] = sgg[0][i], sgg[0][i] = tmp;
			i *= 2;
		}
		else {
			int tmp;
			tmp = sgg[1][i * 2 + 1], sgg[1][i * 2 + 1] = sgg[1][i], sgg[1][i] = tmp;
			tmp = sgg[0][i * 2 + 1], sgg[0][i * 2 + 1] = sgg[0][i], sgg[0][i] = tmp;
			i *= 2, i += 1;
		}
	}
}
void push_up(int n) {
	for(int i = n;i > 1;) {
		if(sgg[1][i / 2] > sgg[1][i]) {
			int tmp;
			tmp = sgg[1][i / 2], sgg[1][i / 2] = sgg[1][i], sgg[1][i] = tmp;
			tmp = sgg[0][i / 2], sgg[0][i / 2] = sgg[0][i], sgg[0][i] = tmp;
			push_down(i);
			i /= 2;		
		}
		else return;
	}
}
int sgg_pop() {
	int popment = sgg[1][1];
	sgg[1][1] = sgg[1][sggl - 1], sgg[0][1] = sgg[0][sggl - 1], sggl--;
	push_down(1);
	/*
	printf("sggl: %d\n", sggl);
	for(int i = 1;i != sggl;i++) {
		printf("%d,%d ", sgg[0][i], sgg[1][i]);
	}
	printf("\n");
	*/
	return popment;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);
		ans = 0, sggl = 1;
		for(int i = 0;i != n;i++) {
			int l, m, n;
			scanf("%d%d%d", &l, &m, &n);
			if(l >= m && m >= n) seq[0][i] = l, seq[1][i] = m, seq[2][i] = n, to[0][i] = 0, to[1][i] = 1, to[2][i] = 2, to2[i] = 0, cnt[0]++;
			else if(l >= n && n >= m) seq[0][i] = l, seq[1][i] = n, seq[2][i] = m, to[0][i] = 0, to[1][i] = 2, to[2][i] = 1, to2[i] = 0, cnt[0]++;
			else if(m >= l && l >= n) seq[0][i] = m, seq[1][i] = l, seq[2][i] = n, to[0][i] = 1, to[1][i] = 0, to[2][i] = 2, to2[i] = 1, cnt[1]++;
			else if(m >= n && n >= l) seq[0][i] = m, seq[1][i] = n, seq[2][i] = l, to[0][i] = 1, to[1][i] = 2, to[2][i] = 0, to2[i] = 1, cnt[1]++;
			else if(n >= l && l >= m) seq[0][i] = n, seq[1][i] = l, seq[2][i] = m, to[0][i] = 2, to[1][i] = 0, to[2][i] = 1, to2[i] = 2, cnt[2]++;
			else if(n >= m && m >= l) seq[0][i] = n, seq[1][i] = m, seq[2][i] = l, to[0][i] = 2, to[1][i] = 1, to[2][i] = 0, to2[i] = 2, cnt[2]++;
			ans += seq[0][i];
		}
		int tar_bm = -1;
		for(int i = 0;i != 3;i++) {
			//printf("cnt[%d]: %d\n", i, cnt[i]);
			if(cnt[i] > n / 2) tar_bm = i;
		}
		/*
		for(int i = 0;i != 3;i++) {
			for(int j = 0;j != n;j++) {
				printf("%d ", seq[i][j]);
			}
			printf("\n");
		}
		*/
		//printf("ans: %d, tar_bm: %d\n", ans, tar_bm);
		if(tar_bm == -1) {}
		else {
			for(int i = 0;i != n;i++) {
				if(to2[i] == tar_bm) {
					//printf("%d: %d - %d = %d\n", i, seq[0][i], seq[1][i], seq[0][i] - seq[1][i]);
					sgg[0][sggl] = i;
					sgg[1][sggl++] = seq[0][i] - seq[1][i];
				}
			}
			for(int i = 1;i != sggl;i++) {
				push_up(i);
			}
			/*
			printf("sggl: %d\n", sggl);
			for(int i = 1;i != sggl;i++) {
				printf("%d,%d ", sgg[0][i], sgg[1][i]);
			}
			printf("\n");
			*/ 
			//printf("nl: %d - %d = %d\n", cnt[tar_bm], n / 2, cnt[tar_bm] - n / 2);
			for(int i = 0;i != cnt[tar_bm] - n / 2;i++) {
				//printf("%d: %d\n", i, ans);
				ans -= sgg_pop();
			}
		}
		printf("%d\n", ans);
	}
	return 0; 
}
