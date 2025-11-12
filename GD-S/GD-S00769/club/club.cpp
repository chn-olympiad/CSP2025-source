#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T,n,a[N][5],b[N],tot,v[N],cv[N];
int cnt1,cnt2,cnt3,ans,lim;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> T;
	while (T--){
		cin >> n;
		cnt1 = 0,cnt2 = 0,cnt3 = 0,ans = 0,tot = 0;
		lim = n / 2;
		for (int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				cnt1++;
				ans += a[i][1]; 
				v[i] = 1;
				cv[i] = max(a[i][2],a[i][3]);
			}
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				cnt2++;
				ans += a[i][2];
				v[i] = 2;
				cv[i] = max(a[i][1],a[i][3]);
			}
			else{
				cnt3++;
				ans += a[i][3];
				v[i] = 3;
				cv[i] = max(a[i][1],a[i][2]);
			}
		}
		if (cnt1 <= lim && cnt2 <= lim && cnt3 <= lim){
			cout << ans << '\n';
			continue;
		}
		int mx = 0;
		if (cnt1>lim)mx=1;
		else if(cnt2>lim)mx=2;
		else mx=3;
		for (int i = 1;i <= n;i++){
			if (v[i] == mx){
				b[++tot] = a[i][v[i]] - cv[i];
			}
		}
		sort(b+1,b+tot+1);
		int x = max(cnt1,max(cnt2,cnt3)) - lim;
		for (int i = 1;i <= x;i++){
			ans -= b[i];
		}
		cout << ans << '\n';
	}
	return 0;
}












