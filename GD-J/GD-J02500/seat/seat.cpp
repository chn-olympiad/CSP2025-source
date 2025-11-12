#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int sum, mod, cnt;
bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n*m; i++){
		cin >> a[i];
	}
	sum = a[1];
	sort(a+1, a+n*m+1, cmp);
	int id = 1;
	while (a[id]!=sum) id ++;
	cnt = id/n;
	mod = id%n;
	if (mod==0) mod = n;
	else cnt ++;
	cout << cnt << " ";
	if (cnt%2==1){
		cout << mod;
	} else {
		cout << n-mod+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
