#include <bits/stdc++.h>
using namespace std;
const int Max = 1e2+5;
int a[Max][Max],paixv[Max][Max],pai1[Max],club[4],zhi[Max][Max];
long long biaoji[Max];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++) {
		for(int z = 0; z<=Max; z++) {
			for(int j = 0; j<=Max; j++) {
				a[z][j] = 0;
			}
		}

		for(int z = 0; z<=Max; z++) {
			for(int j = 0; j<=Max; j++) {
				paixv[z][j] = 0;
			}
		}

		for(int z = 0; z<=Max; z++) {
			for(int j = 0; j<=Max; j++) {
				zhi[z][j] = 0;
			}
		}

		for(int z = 0; z<=4; z++) {
			club[z]==0;
		}

		for(int z = 0; z<=Max; z++) {
			pai1[z] = 0;
		}
		
		for(int z = 0;z<=Max;z++){
			biaoji[z]  = Max;
		}
		int n = 0;
		int sum = 0;


		cin >> n;
		for(int j = 1; j<=n; j++) {
			for(int m = 1; m<=3; m++) {
				cin >> a[j][m];
				biaoji[m*a[j][m]]=0; 
			}
		}




		for(int z = 1; z<=n; z++) {
			for(int j = 1; j<=3; j++) {
				paixv[z][j] = a[z][j];
				pai1[j] = paixv[z][j];
			}
			sort(pai1+1,pai1+3+1);
			for(int m = 1; m<=3; m++) {
				paixv[z][m] = pai1[m];
				int lin = paixv[z][m];
				for(int x = 1; x<=n; x++) {
					for(int y = 1; y<=3; y++) {
						if(lin == a[x][y]&&z==x&&biaoji[m*lin]!=Max) {
							zhi[z][m] = y;
						}
					}
				}
			}
		}


		for(int z = 1; z<=n; z++) {
			for(int j = 3; j>=1;) {
				if(club[zhi[z][j]]+1<=n/2) {
					club[zhi[z][j]]++;
					sum+=paixv[z][j];
					break;
				} else {
					j--;
				}
			}
		}

		cout << sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

