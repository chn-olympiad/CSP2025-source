#include <cstdio>
const int N = 15;
int cnt[N];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char t;
	while(scanf("%c", &t) != EOF) {
		if((t >= 'a' && t <= 'z') || (t >= '0' && t <= '9')) {
			if(t >= '0' && t <= '9') cnt[t - '0']++;
		} else {
			break;
		}
	}
	for(int i = 9; i >= 0; i--) {
		while(cnt[i]) {
			printf("%d", i);
			cnt[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}