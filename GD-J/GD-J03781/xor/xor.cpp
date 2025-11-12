#include <iostream>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	int ans;
	cin >> n >> k;
	int num[n];
	int ind[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			ind[i][j] = 0;
		}
	}
	bool flag1 = true;
	bool flag2 = true;
	int xors;
	for (int i = 0; i < n; i++){
		cin >> num[i];
		if (num[i] != 1) flag1 = false;
	}
	if (flag1) {
		cout << n;
		flag2 = false;
	}
	for (int l = 0; l < n; l++){
		xors = l;
		for (int r = l; r < n; r++){
			for (int i = l+1; i <= r; i++){
				xors = xors xor num[i];
			}
			if (xors == k) ind[l][r] = xors;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
