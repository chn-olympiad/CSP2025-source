#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define fo(i,j,k,l) for(int i = j;i <= k;i += l)
#define lowbit(x) (x & -x)
using namespace std;
int T;
int n,a[100005][5];
int cnt1,cnt2,cnt3;
int b[5][100005];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T --) {
		cin >> n;
		fo(i,1,n,1)scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		cnt1 = cnt2 = cnt3 = 0;
		int ans = 0;
		fo(i,1,n,1) {
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				cnt1 ++;
				ans += a[i][1];
				b[1][cnt1] = min(a[i][1] - a[i][2],a[i][1] - a[i][3]);
			}
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				cnt2 ++;
				ans += a[i][2];
				b[2][cnt2] = min(a[i][2] - a[i][1],a[i][2] - a[i][3]);
			}
			else {
				cnt3 ++;
				ans += a[i][3]; 
				b[3][cnt3] = min(a[i][3] - a[i][2],a[i][3] - a[i][1]);
			}
		}
		if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
			printf("%lld\n",ans);
			continue; 
		}
		if(cnt1 > n / 2)  {
			sort(b[1] + 1,b[1] + 1 + cnt1);
			fo(i,1,cnt1 - (n / 2),1) {
				ans -= b[1][i];
			}
			printf("%lld\n",ans);
		}
		else if(cnt2 > n / 2)  {
			sort(b[2] + 1,b[2] + 1 + cnt2);
			fo(i,1,cnt2 - (n / 2),1) {
				ans -= b[2][i];
			}
			printf("%lld\n",ans);
		}
		else if(cnt3 > n / 2)  {
			sort(b[3] + 1,b[3] + 1 + cnt3);
			fo(i,1,cnt3 - (n / 2),1) {
				ans -= b[3][i];
			}
			printf("%lld\n",ans);
		}
	} 
	return 0;
}

