//GZ-S00200  方晨亦    观山湖中学
#include<bits/stdc++.h>
using namespace std;



int t, n, cnt1 = 0, cnt2 = 0;
int a[10];
int s1 = 0, s2 = 0, s3 = 0;

int main(){



	freopen("club1.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n;
		cnt1 = n/2;
		int m[1000][n+5];
		for(int j = 1; j <= n; j++) {
			cin >> a[1] >> a[2] >> a[3];
			m[j][1] = a[1];
			m[j][2] = a[2];
			m[j][3] = a[3];
			if(max(a[1], max(a[2], a[3])) == a[1]) {
				s1++;
				cnt2 += a[1];
			} else if(max(a[1], max(a[2], a[3])) == a[2]) {
				s2++;
				cnt2 += a[2];
			} else if(max(a[1], max(a[2], a[3])) == a[3]) {
				s3++;
				cnt2 += a[3];
			}
		}
		a[1] = 0;
		a[2] = 0;
		a[3] = 0;
		if(s1 <= cnt1 && s2 <= cnt1 && s3 <= cnt1) {
			cout << cnt2 << endl;
			s1 = 0;
			s2 = 0;
			s3 = 0;
		} else {
			if(s1 > cnt1) {
				for(int j = 1; j <= n-1; j++){
					if(m[j][2] > m[j][3]){
						cnt2 = cnt2 - m[j][1] + m[j][2];
					}
					else {
						cnt2 = cnt2 - m[j][1] + m[j][3];
					}
				}
			}
			else if(s2 > cnt1) {
				for(int j = 1; j <= n-1; j++){
					if(m[j][1] >= m[j][3]){
						cnt2 = cnt2 - m[j][2] + m[j][1];
					}
					else {
						cnt2 = cnt2 - m[j][2] + m[j][3];
					}
					if(s2 <= cnt1){
						cout << cnt2 << endl;
						return 0;
					}
				}

			}
			else if(s3 > cnt1) {
				for(int j = 1; j <= n-1; j++){
					if(m[j][2] > m[j][1]){
						cnt2 = cnt2 - m[j][3] + m[j][2];
					}
					else {
						cnt2 = cnt2 - m[j][3] + m[j][1];
					}
				}
			}
			cout << cnt2 << endl;
		}
		cnt2 = 0;
	}
	return 0;
}

