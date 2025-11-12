#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010][5];
int main() {
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		long long ans = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= 3;j++) {
				cin >> a[i][j];
			}
		}
		int suma = 0,sumb = 0;
		int cnta = 0,cntb = 0;
		int x[200010],y[20010];
		int cntc = 0,cntd = 0;
		int z[100010],q[100010];
		for(int i = 1;i <= n;i++) {
			z[i] = 0;
			q[i] = 0;
		}
		for(int i = 1;i <= 2 * n;i++) {
			x[i] = 0;
			y[i] = 0;  
		}
		for(int i = 1;i <= n;i++) {
			if(a[i][1] >= a[i][2]) {
				cnta++;
				x[cnta] = a[i][1];
				cntc++;
				z[cntc] = a[i][2]; 
			} else if(a[i][2] >= a[i][1]){
				cntb++;
				y[cntb] = a[i][2];
				cntd++;
				q[cntd] = a[i][1];
			}
		}
		sort(x + 1,x + 1 + cnta);
		sort(y + 1,y + 1 + cntb);
		for(int i = cnta,j = 1;j <= n / 2 && i;j++,i--) {
			suma += x[i];
		}
		for(int i = cntb,j = 1;j <= n / 2 && i;j++,i--) {
			sumb += y[i];
		}
		if(suma >= sumb) {
			for(int i = cntb + 1,j = 1;j <= cntc;i++,j++) {
				y[i] = z[j];
			}
			sort(y + 1,y + 1 + cntb + cntc);
			if(cnta <= n / 2) {
				ans += suma;
				for(int i = cntb + cntc,j = 1;i && j <= n - cnta;i--,j++) {
					ans += y[i];
				}
			} else {
				for(int i = cnta,j = 1;j <= n / 2&& i;i--,j++) {
					ans += x[i];
				}
				for(int i = cntb + cntc,j = 1;j <= n / 2 && i;i--,j++) {
					ans += y[i];
				}
			}
		} else if(sumb >= suma) {
			for(int i = cnta + 1,j = 1;j <= cntd;i++,j++) {
				x[i] = q[j];
			}
			sort(x + 1,x + 1 + cnta + cntd);
			if(cntb <= n / 2) {
				ans += sumb;
				for(int i = cnta + cntd,j = 1;i && j <= n - cntb;i--,j++) {
					ans += x[i];
				}
			} else {
				for(int i = cntb,j = 1;j <= n / 2&& i;i--,j++) {
					ans += y[i];
				}
				for(int i = cnta + cntd,j = 1;j <= n / 2 && i;i--,j++) {
					ans += x[i];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
