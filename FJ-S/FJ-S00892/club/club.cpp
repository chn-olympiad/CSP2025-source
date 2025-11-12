/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int t[100005][3],a[100005],b[100005],c[100005],cnt1,cnt2,cnt3;
bool cmp(int i,int j) {
	return max(t[i][1],t[i][2])-t[i][0] < max(t[j][1],t[j][2])-t[j][0];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n,sum;
	scanf("%d",&T);
	for (int k = 1;k <= T;k++) {
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) {
			scanf("%d%d%d",&t[i][0],&t[i][1],&t[i][2]);
		}
		for (int i = 1;i <= n;i++) {
			if (t[i][0] > t[i][1] && t[i][0] > t[i][2]) {
				a[++cnt1] = i;
			}
			else if (t[i][1] > t[i][0] && t[i][1] > t[i][2]) {
				b[++cnt2] = i;
			}
			else {
				c[++cnt3] = i;
			}
		}
		if (!(cnt1*2 <= n && cnt2*2 <= n && cnt3*2 <= n)) {
			if (cnt2*2 > n) {
				swap(cnt1,cnt2);
				for (int i = 1;i <= n;i++) {
					swap(a[i],b[i]);
					swap(t[i][0],t[i][1]);
				}
			}
			else if (cnt3*2 > n) {
				swap(cnt1,cnt3);
				for (int i = 1;i <= n;i++) {
					swap(a[i],c[i]);
					swap(t[i][0],t[i][2]);
				}
			}
			sort(a+1,a+cnt1+1,cmp);
			for (;cnt1*2 > n;) {
				if (t[a[cnt1]][0] > t[a[cnt1]][1]) {
					b[++cnt2] = a[cnt1--];
				}
				else{
					c[++cnt3] = a[cnt1--];
				}
			}
		}
		sum = 0;
		for (int i = 1;i <= cnt1;i++) {
			sum += t[a[i]][0];
		}
		for (int i = 1;i <= cnt2;i++) {
			sum += t[b[i]][1];
		}
		for (int i = 1;i <= cnt3;i++) {
			sum += t[c[i]][2];
		}
		printf("%d\n",sum);
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
	}
	return 0;
}
