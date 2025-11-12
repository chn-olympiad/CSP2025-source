#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL a[20000000];
LL n;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	LL ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				if(a[i] + a[j] > a[k]){
					ans++;
				}
			}
		}
	}
	cout << ans;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
