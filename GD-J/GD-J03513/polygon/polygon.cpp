#include<bits/stdc++.h>
using namespace std;

int n, a[10000010];


int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[1000010];
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(a[1] + a[2] + a[3] > a[3] * 2) cout << 1;
	else cout << 0;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
