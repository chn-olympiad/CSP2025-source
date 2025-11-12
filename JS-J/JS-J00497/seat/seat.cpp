#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen(stdin, 'r', "seat.in");
	freopen(stdout, 'w', "seat.out");
	int n, m, r;
	cin >> n >> m;
	for (int i = 1;i <= n * m;i ++){
		cin >> a[i];
		if(i == 1) r = a[i];
	}
	int pm = 1;
	for (int i = 1;i <= n * m;i ++){
		if (a[i] > r) pm ++;
	}
	int a = pm / n;
	int b = pm % n;
	if (a % 2 == 0) b = m - b + 1;
	cout << a << ' ' << b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
