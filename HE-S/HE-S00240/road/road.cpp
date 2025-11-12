//Áù°ÙÁùÊ®Áù»¹²¹Üö 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	/////////////////////////////////////////////////////////////////
	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		ans += c;
	}
	cout << ans;
	/////////////////////////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	return 0;
}
