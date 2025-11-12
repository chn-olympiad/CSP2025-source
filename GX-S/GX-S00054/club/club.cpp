#include<bits/stdc++.h>

using namespace std;

long long T, n, a[100005][4], ans;
long long ch[4][100005], maxn[100005], sec[100005], cnt[4];

void init(){
	for(int i = 0; i <= 100000; i++){
		maxn[i] = 0;
		sec[i] = 0;
	}
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 100000; j++){
			ch[i][j] = 0;
		}
	}
	cnt[1] = 0;
	cnt[2] = 0;
	cnt[3] = 0;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while(T--){
		ans = 0;
		init();
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++){
			scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
			maxn[i] = max({a[i][1], a[i][2], a[i][3]});
			ans += maxn[i];
			if(maxn[i] == a[i][1]) {
				cnt[1]++;
				ch[1][cnt[1]] = i;
			}else if(maxn[i] == a[i][2]) {
				cnt[2]++;
				ch[2][cnt[2]] = i;
			}else {
				cnt[3]++;
				ch[3][cnt[3]] = i;
			}
			for(int j = 1; j <= 3; j++){
				if(a[i][j] != maxn[i]){
					sec[i] = max(sec[i], a[i][j]);
				}
			}
		}
		for(int i = 1; i <= 3; i++){
			if(cnt[i] > n / 2){
				int s[100005] = {100000};
				for(int j = 1; j <= cnt[i]; j++){
					int x = ch[i][j];
					s[j] = maxn[x] - sec[x];
				}
				sort(s + 1, s + cnt[i] + 1);
				for(int j = 1; j <= cnt[i] - (n / 2); j++){
					ans -= s[j];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
