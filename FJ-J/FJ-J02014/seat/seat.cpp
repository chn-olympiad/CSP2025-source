#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	int shi = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
		if (a[i] > a[1]){
			shi ++;
		}
	}
	if (n == 1 && m == 1){
		cout << 1 << " " << 1;
	}else {
		int hang, lie;
		lie = (shi + n - 1) / n;
		hang = shi % n;
		if (hang == 0){
			hang = n;
		}
		if (lie % 2 == 0){
			hang = n - hang + 1;
		}
		cout << lie << " " << hang;
	}
	return 0;
}

