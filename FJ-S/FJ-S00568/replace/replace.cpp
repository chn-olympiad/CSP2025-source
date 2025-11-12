#include <cstdio>
#include <cstring>

char s[3][105][200];
int s2l[105];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%s%s", s[1][i], s[2][i]);
		s2l[i]=strlen(s[2][i]);
	}
	for (int i = 1 ; i <= q ; i ++) {
		char t1[2005], t2[2005];
		scanf("%s%s", t1, t2);
		int cnt = 0;
		for (int i = 1 ; i < n ;i ++) {
			char *pos = strstr(t1, s[1][i]);
			while (pos) {
				int id = pos - t1;
				cnt += !(strcmp(pos+s2l[i], t2+id+s2l[i]) || strncmp(s[2][i], t2+id, s2l[i])
					|| strncmp(t1, t2, id));
				// for (int j = 0 ; ; j ++) {
				// 	if (s[2][i][j]==0) {
				// 		cnt++;
				// 		printf("%d ", i);
				// 		break;
				// 	}
				// 	if (s[2][i][j]!=t2[id+j]) {
				// 		break;
				// 	}
				// }
				pos = strstr(pos+1, s[1][i]);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
