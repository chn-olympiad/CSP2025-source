#include <bits/stdc++.h>
using namespace std;
int a[111111], b[111111], c[111111], d[111111], f[111111];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		for(int i = 1; i <= m; i++){
			cin >> a[i] >> b[i] >> c[i];
			d[i] = max(a[i], b[i]);
			if(c[i] > d[i]){
				d[i] = c[i];
				f[i] = 3;
			}else{
				if(d[i] == a[i]){
					f[i] = 1;
				}else{
					f[i] = 2;
				}
			}
		}
		int q1 = 0, w1 = 0, e1 = 0, q2 = 0, w2 = 0, e2 = 0;
		for(int i = 1; i <= m; i++){
			if(f[i] == 1){
				q1++;
				q2 += d[i];
			}
			if(f[i] == 2){
				w1++;
				w2 += d[i];
			}
			if(f[i] == 3){
				e1++;
				e2 += d[i];
			}
		}
		if(q1 <= m/2 && w1 <= m/2 && e1 <= m/2){
			cout << q2+w2+e2 << '\n';
		}else if(q1 > m/2){
			while(q1 > m/2){
				int minn1 = 9999999, minn2 = 0;
				for(int i = 1; i <= m; i++){
					if(f[i] == 1 && a[i] - max(b[i], c[i]) < minn1){
						minn1 = a[i] - max(b[i], c[i]);
						minn2 = i;
					}
				}
				if(b[minn2] > c[minn2] && w1+1 <= m/2){
					q1--;
					w1++;
					q2 -= a[minn2];
					w2 += b[minn2];
					f[minn2] = 2;
				}else if(b[minn2] > c[minn2] && w1+1 > m/2){
					q1--;
					e1++;
					q2 -= a[minn2];
					e2 += c[minn2];
					f[minn2] = 3;
				}else if(c[minn2] > b[minn2] && e1+1 <= m/2){
					q1--;
					e1++;
					q2 -= a[minn2];
					e2 += c[minn2];
					f[minn2] = 3;
				}else{
					q1--;
					w1++;
					q2 -= a[minn2];
					w2 += b[minn2];
					f[minn2] = 2;
				}
			}
			cout << q2+w2+e2 << '\n';
		}else if(w1 > m/2){
			while(w1 > m/2){
				int minn1 = 9999999, minn2 = 0;
				for(int i = 1; i <= m; i++){
					if(f[i] == 2 && b[i] - max(a[i], c[i]) < minn1){
						minn1 = b[i] - max(a[i], c[i]);
						minn2 = i;
					}
				}
				if(a[minn2] > c[minn2] && q1+1 <= m/2){
					w1--;
					q1++;
					w2 -= b[minn2];
					q2 += a[minn2];
					f[minn2] = 1;
				}else if(a[minn2] > c[minn2] && q1+1 > m/2){
					w1--;
					e1++;
					w2 -= b[minn2];
					e2 += c[minn2];
					f[minn2] = 3;
				}else if(c[minn2] > a[minn2] && e1+1 <= m/2){
					w1--;
					e1++;
					w2 -= b[minn2];
					e2 += c[minn2];
					f[minn2] = 3;
				}else{
					w1--;
					q1++;
					w2 -= b[minn2];
					q2 += a[minn2];
					f[minn2] = 1;
				}
			}
			cout << q2+w2+e2 << '\n';
		}else{
			while(e1 > m/2){
				int minn1 = 9999999, minn2 = 0;
				for(int i = 1; i <= m; i++){
					if(f[i] == 3 && c[i] - max(a[i], b[i]) < minn1){
						minn1 = c[i] - max(a[i], b[i]);
						minn2 = i;
					}
				}
				if(a[minn2] > b[minn2] && q1+1 <= m/2){
					e1--;
					q1++;
					e2 -= c[minn2];
					q2 += a[minn2];
					f[minn2] = 1;
				}else if(a[minn2] > b[minn2] && q1+1 > m/2){
					e1--;
					w1++;
					e2 -= c[minn2];
					w2 += b[minn2];
					f[minn2] = 2;
				}else if(b[minn2] > a[minn2] && w1+1 <= m/2){
					e1--;
					w1++;
					e2 -= c[minn2];
					w2 += b[minn2];
					f[minn2] = 2;
				}else{
					e1--;
					q1++;
					e2 -= c[minn2];
					q2 += a[minn2];
					f[minn2] = 1;
                }
			}
			cout << q2+w2+e2 << '\n';
		}
	}
	return 0;
}
