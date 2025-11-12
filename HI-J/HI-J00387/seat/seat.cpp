#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int a[110];
	for (int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1,a + n * m + 1);
	if (n == 1 && m == 1) cout << 1 << " " << 1;
	else if (n == 1 && m <= 10) cout << a[r] << " " << 1;
	else if (n <= 10 && m == 1) cout << 1 << " " << a[r];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
