#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct node{
	int s1,s2;
};
bool cmp (node x, node y){
	return x.s1 > y.s1;
}
int t,n,a[N][5],c[5],l[N],r[N];
node b[5][N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		memset (c, 0, sizeof c);
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++){
			int maxn = 0, maxn2 = 0, k;
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
				if (a[i][j] > maxn){
			    	maxn2 = maxn;
					maxn = a[i][j];
					k = j;
				}
				else if (a[i][j] > maxn2) maxn2 = a[i][j];
			}
			node X;
			X.s1 = maxn;
			X.s2 = maxn2;
			b[k][++c[k]] = X;
		}
		for (int i = 1; i <= 3; i++){
			if (c[i] > n/2){
			    int cnt1 = 0, cnt2 = 0;
				sort(b[i] + 1,b[i] + 1 + c[i],cmp);
				for (int j = 1; j <= c[i]; j++){
					if (j <= n/2){
						ans += b[i][j].s1;
						l[++cnt1] = b[i][j].s1 - b[i][j].s2;
					}
					else {
						ans += b[i][j].s2;
						r[++cnt2] = b[i][j].s1 - b[i][j].s2;
					}
				}
				int ql = 1,qr = cnt2;
				sort (l + 1, l + 1 + cnt1);
				sort (r + 1, r + 1 + cnt2);
				while (r[qr] > l[ql] && qr > 0 && ql <= cnt1){
					ans += r[qr] - l[ql];
					qr--;
					ql++;
				}
			}
			else{
				for (int j = 1; j <= c[i]; j++)
					ans += b[i][j].s1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
