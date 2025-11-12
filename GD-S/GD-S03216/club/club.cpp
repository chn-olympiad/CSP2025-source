#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5;

int t, n, a[MXN][3], ns;
int tp[MXN], cnt[3];
vector< int > nums;

int read(){
	int x = 0;
	char c = getchar();
	for(;c < '0' || c > '9';) c = getchar();
	for(;c >= '0' && c <= '9';c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int i, j;
	for(t = read();t;--t){
		n = read();
		ns = 0;
		for(i = 0;i < 3;++i) cnt[i] = 0;
		for(i = 0;i < n;++i){
			int mx = 0;
			for(j = 0;j < 3;++j){
				a[i][j] = read();
				mx = max(mx, a[i][j]);
			}
			for(j = 0;j < 3;++j)
				if(mx == a[i][j]){
					ns += a[i][j];
					tp[i] = j;
					++cnt[j];
					break;
				}
		}
		if(cnt[0] <= (n >> 1) && cnt[1] <= (n >> 1) && cnt[2] <= (n >> 1)){
			printf("%d\n", ns);
			continue;
		}
		int need;
		for(i = 0;i < 3;++i)
			if(cnt[i] > (n >> 1)) need = i;
		nums.clear();
		for(i = 0;i < n;++i)
			if(tp[i] == need){
				int mx = 0;
				for(j = 0;j < 3;++j)
					if(j != need) mx = max(mx, a[i][j]);
				nums.push_back(a[i][need] - mx);
			}
		sort(nums.begin(), nums.end());
		for(i = 0;i < cnt[need] - (n >> 1);++i) ns -= nums[i];
		printf("%d\n", ns);
	}
	return 0;
}
