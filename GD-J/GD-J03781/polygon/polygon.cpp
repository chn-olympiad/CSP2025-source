#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int sticks[n];
	for (int i = 0; i < n; i++){
		cin >> sticks[i];
	}
	int ans1 = 1;
	int ans2 = 1;
	int ans3;
	for (int i = 3; i <= n; i++){
		for (int j = 0; j < i; j++){
			ans1 = ans1 * (n-j);
			ans2 = ans2 * (j+1);
		}
	}
	cout << (ans1 / ans2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
