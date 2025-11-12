#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	int n;
	int l[t];
	for (int i = 0; i < t; i++){
		cin >> n;
		int m[n];
		for (int j = 0; j < n; j++){
			cin >> m[j];
		}
		l[i] = m;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
