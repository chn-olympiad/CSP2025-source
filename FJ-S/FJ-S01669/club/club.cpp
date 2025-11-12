#include<iostream>
#include<algorithm>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
int T,n,a[N],b[N],c[N],f1[N],f2[N],f3[N],best[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		int sum = 0,cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if(a[i] >= b[i] && a[i] >= c[i]){
				sum += a[i];
				f1[++cnt1] = i;
				continue;
			}
			if(b[i] >= a[i] && b[i] >= c[i]){
				sum += b[i];
				f2[++cnt2] = i;
				continue;
			}
			if(c[i] >= a[i] && c[i] >= b[i]){
				sum += c[i];
				f3[++cnt3] = i;
				continue;
			}
		}
		if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2){
			cout << sum << endl;
		} else {
			int cnt4 = 0;
			if(cnt1 > n / 2){
				for(int i = 1;i <= cnt1;i++){
					best[++cnt4] = min(a[f1[i]] - b[f1[i]],a[f1[i]] - c[f1[i]]);
				}
			}
			if(cnt2 > n / 2){
				for(int i = 1;i <= cnt2;i++){
					best[++cnt4] = min(b[f2[i]] - a[f2[i]],b[f2[i]] - c[f2[i]]);
				}
			}
			if(cnt3 > n / 2){
				for(int i = 1;i <= cnt3;i++){
					best[++cnt4] = min(c[f3[i]] - a[f3[i]],c[f3[i]] - b[f3[i]]);
				}
			}
			sort(best + 1,best + cnt4 + 1);
			for(int i = 1;i <= cnt4 - n / 2;i++){
				sum -= best[i];
			}
			cout << sum << endl;
		}
	}
	return 0;
}
