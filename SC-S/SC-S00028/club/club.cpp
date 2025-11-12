#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][7];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		int n;
		cin >> n;
		int cnt1,cnt2,cnt3,sum = 0;
		cnt1 = cnt2 = cnt3 = 0;
		for(int j = 1;j <= n;j++){
			cin >> a[j][1] >> a[j][2] >> a[j][3];
			a[j][4] = max(max(a[j][2],a[j][3]),a[j][1]);
			if(a[j][4] == a[j][1]){
//				a[j][5] = min(a[j][2],a[j][3]);
//				a[j][6] = max(a[j][2],a[j][3]);
				cnt1++;
				if(cnt1 > n / 2){
					cnt1--;
					if(a[j][2] == max(a[j][2],a[j][3])){
						if((cnt2 + 1) > n / 2){
							cnt3++;
//							cout << 3 << " " << a[j][3] << "\n";
							sum += a[j][3];
						}else{
							cnt2++;
//							cout << 2 << " " << a[j][2] << "\n";
							sum += a[j][2];
						}
					}else{
						if((cnt3 + 1) > n / 2){
							cnt2++;
//							cout << 2 << " " << a[j][2] << "\n";
							sum += a[j][2];
						}else{
							cnt3++;
//							cout << 3 << " " << a[j][3] << "\n";
							sum += a[j][3];
						}
					}
				}else{
//					cout << 1 << " " << a[j][1] << "\n";
					sum += a[j][1];
				}
			}
			if(a[j][4] == a[j][2]){
//				a[j][5] = min(a[j][1],a[j][3]);
//				a[j][6] = max(a[j][1],a[j][3]);
				cnt2++;
				if(cnt2 > n / 2){
					cnt2--;
					if(a[j][1] == max(a[j][1],a[j][3])){
						if((cnt1 + 1) > n / 2){
							cnt3++;
//							cout << 3 << " " << a[j][3] << "\n";
							sum += a[j][3];
						}else{
							cnt1++;
//							cout << 1 << " " << a[j][1] << "\n";
							sum += a[j][1];
						}
					}else{
						if((cnt3 + 1) > n / 2){
							cnt1++;
//							cout << 1 << " " << a[j][3] << "\n";
							sum += a[j][1];
						}else{
							cnt3++;
//							cout << 3 << " " << a[j][3] << "\n";
							sum += a[j][3];
						}
					}
				}else{
//					cout << 2 << " "<< a[j][2] << "\n";
					sum += a[j][2];
				}
			}
			if(a[j][4] == a[j][3]){
//				a[j][5] = min(a[j][2],a[j][1]);
//				a[j][6] = max(a[j][2],a[j][1]);
				cnt3++;
				if(cnt3 > n / 2){
					cnt3--;
					if(a[j][1] == max(a[j][1],a[j][2])){
						if((cnt1 + 1) > n / 2){
							cnt2++;
//							cout << 2 << " " << a[j][2] << "\n";
							sum += a[j][2];
						}else{
							cnt1++;
//							cout << 1 << " " << a[j][1] << "\n";
							sum += a[j][1];
						}
					}else{
						if((cnt2 + 1) > n / 2){
							cnt1++;
//							cout << 1 << " " << a[j][1] << "\n";
							sum += a[j][1];
						}else{
							cnt2++;
//							cout << 2 << " " << a[j][2] << "\n";
							sum += a[j][2];
						}
					}
				}else{
//					cout << 3 << " " << a[j][3] << "\n";
					sum += a[j][3];
				}
			} 
		}
		cout << sum << "\n";
	}
	return 0;
}