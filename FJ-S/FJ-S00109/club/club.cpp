#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	bool flag = 0;
	vector<int>b, ans;
	int b78o = t;
	int bro[101];
	int z = 0;
	while(t--){
		int n;
		cin >> n;
		if(n == 2) flag = 1;
		int a[n][4];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 3; j++){
				cin >> a[i][j];
			}
		}
		if(n == 2){
			int nmax1 = a[0][0], nmax2 = a[0][1];
			nmax1 = max(nmax1, a[1][0]);
			nmax2 = max(nmax2, a[1][1]);
			int x[6] = {0};
			x[1] = nmax1 + nmax2;
			x[2] = nmax1 + a[0][2];
			x[3] = nmax2 + a[1][2];
			x[4] = nmax2 + a[0][2];
			x[5] = nmax1 + a[1][2];
			int tm = INT_MIN;
			for(int i = 1; i <= 5; i++){
				tm = max(x[i], tm);
			}
			bro[z++] = tm;
			continue;
		}
		int v = n / 2;
		int dp1[n + 5][v] = {{0}}, dp2[n + 5][v] = {{0}}, dp3[n + 5][v] = {{0}};
		for(int i = 1; i < n; i++){
			for(int j = v; j >= 1; j--){
				dp1[i][v] = max(dp1[i - 1][j - 1], dp1[i - 1][j - 1] + a[i - 1][0]);
			}
		}
		for(int i = 1; i < n; i++){
			for(int j = v; j >= 1; j--){
				dp2[i][v] = max(dp2[i - 1][j - 1], dp2[i - 1][j - 1] + a[i - 1][1]);
			}
		}
		for(int i = 1; i < n; i++){
			for(int j = v; j >= 1; j--){
				dp3[i][v] = max(dp3[i - 1][j - 1], dp3[i - 1][j - 1] + a[i - 1][2]);
			}
		}
		b.push_back(dp1[n - 1][v] + dp2[n - 1][v] + dp3[n - 1][v]);
	}
	if(flag == 0){
		for(int i = 0; i < b78o; i++){
			cout << b[i] << "\n";
		}
	}	
	else{
		for(int i = 0; i < z; i++){
			cout << bro[i] << "\n";
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
