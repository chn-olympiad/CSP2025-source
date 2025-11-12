#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define vc vector
#define vci vc<int>
#define psb push_back
using namespace std;
int n, t;
int a[200005], b[200005], c[200005], ca, cb, cc;
ll ans;
vci hva, hvb, hvc;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ca = cb = cc = ans = 0;
		hva.clear();
		hvb.clear();
		hvc.clear();
		cin >> n;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			ans += max(a[i], max(b[i], c[i]));
			if(a[i] == max(a[i], max(b[i], c[i]))) ca++, hva.psb(a[i] - max(b[i], c[i]));
			else if(b[i] == max(a[i], max(b[i], c[i]))) cb++, hvb.psb(b[i] - max(a[i], c[i]));
			else cc++, hvc.psb(c[i] - max(b[i], a[i]));
		}
//		cout << ans << ' ' << ca << ' ' << cb << ' ' << cc << endl; 
//		cout << ans << endl;
		if(ca > n / 2){
			sort(hva.begin(), hva.end());
			for(int i = 0; i < ca - n / 2; i++) ans -= hva[i];
		}
		if(cb > n / 2){
			sort(hvb.begin(), hvb.end());
			for(int i = 0; i < cb - n / 2; i++) ans -= hvb[i];
		}
		if(cc > n / 2){
			sort(hvc.begin(), hvc.end());
			for(int i = 0; i < cc - n / 2; i++) ans -= hvc[i];
		}
		cout << ans << endl;
	}
	return 0;
}
