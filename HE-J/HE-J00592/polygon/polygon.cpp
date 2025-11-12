#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n, a[5005], dp[5005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.ans", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(n == 3){
		sort(a + 1, a + n + 1);
		if((a[1] + a[2] + a[3]) > 2 * a[3]) cout << 1 << endl;
		else cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
