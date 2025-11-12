#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int s;
	s = n * m;
	int pts[105];
	for (int i = 1;i <= s;i++) cin >> pts[i];
	int hang, lie;
	int r = pts[1];
	sort(pts + 1,pts + s + 1);
	int p;
	for (int i = s;i >= 1;i--){
		if (pts[i] == r){
			p = s + 1 - i;
			break;
		}
	}
	if (p % n == 0){
		lie = p / n;
	}
	else{
		lie = p / n + 1;
	}
	if (lie % 2 == 1){
		if (p % n == 0){
			hang = n;
		}
		else{
			hang = p % n;
		}
	}
	else{
		hang = n - (p % n) + 1;
	}
	cout << lie << ' ' << hang;
	return 0;
}
