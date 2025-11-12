#include <iostream>
using namespace std;

int n,a[5005],b[5005] = {},ans = 0,bs;
int dfs(int x){
	int bc = 0,m = 0;
	if (x > n){
		return 0;
	}
	b[x] = 1;
	bs++;
	if (bs >= 3){
		for (int i = 1; i <= n; i++){
			if (b[i]){
				bc += a[i];
			}
		}
		for (int i = 1; i <= n; i++){
			if (b[i] && a[i] > m){
				m = a[i];
			}
		}
		bc -= m;
		if (bc > m * 2){
			ans++;
		}
	}
	dfs(x + 1);
	b[x] = 0;
	bs--;
	dfs(x + 1);
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}
