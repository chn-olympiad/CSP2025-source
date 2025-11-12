#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	int ans = 0;
	for (int i = 1;i <= t;i++){
		int n;
		cin >> n;
		for (int j = 1;j <= n;j++){
			int a[3];
			cin >> a[1] >> a[2] >> a[3];
			sort(a + 1,a + n + 1);
			ans += a[1];
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
