// Genshin Impact Start!!

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+5;

int T;
int n;
int a[N][5];
int mxnum[N];
int cnt[5];
int tmp[N];
int main () {
	//freopen("club5.in","r",stdin);
	//freopen("club.out","w",stdout);	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		cnt[1] = cnt[2] = cnt[3] = 0;
		int ans = 0;
		for (int i = 1;i <= n;i++) {
			int mx = 0;
			mxnum[i] = 1;
			for (int j = 1;j <= 3;j++) {
				scanf("%d",&a[i][j]);
				if (a[i][j] > mx) mxnum[i] = j,mx = a[i][j];
			}
			ans += mx;
			cnt[mxnum[i]]++;
		}
		int fd = 0;
		for (int i = 1;i <= 3;i++) if (cnt[i] > n/2) fd = i;
		if (!fd) {
			printf("%d\n",ans);
			continue;
		}
		int k = 0;
		for (int i = 1;i <= n;i++) {
			if (mxnum[i] == fd) {
				if (fd == 1) tmp[++k] = a[i][1]-max(a[i][2],a[i][3]);
				if (fd == 2) tmp[++k] = a[i][2]-max(a[i][1],a[i][3]);
				if (fd == 3) tmp[++k] = a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		sort(tmp+1,tmp+k+1);
		for (int i = 1;i <= k && cnt[fd] > n/2;i++) {
			cnt[fd]--;
			ans -= tmp[i];
		}
		printf("%d\n",ans);
	}	
	return 0;
}
