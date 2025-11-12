#include <bits/stdc++.h>
using namespace std;

int n,ans = 0;;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int maxabbbbbbbbb = 0;
	for (int i = 0;i < n;i++){
		cin >> a[i];
		maxabbbbbbbbb = max(maxabbbbbbbbb,a[i]);
	}
	if (maxabbbbbbbbb == 1){
		for (int i = 2;i < n;i++){
			ans += n-i;
			ans = ans % 998244353;
		}
		cout << ans << endl;
		return 0;
	}
	for (int i = 1;i < pow(2,n);i++){
		int maxn = 0;
		int countb = 0;
		int sumx = 0;
		//cout << i << ':' << endl; 
		for (int j = 0;j < n;j++){
			int p = pow(2,j);
			if (p & i){
				countb += 1;
				sumx += a[j];
				maxn = max(maxn,a[j]);
			}
			//cout << "j:" << pow(2,j) << ' ' << i << ' ' << (p & i) << ' ' << j << ' ' << countb << ' ' << sumx << ' ' << maxn << endl;
		}
		if ((countb >= 3) && (sumx > 2*maxn)){
			ans++;
			//cout << "it's right!" << endl;
		}
		//cout << i << ' ' << countb << ' ' << sumx << ' ' << maxn << ' ' << (countb >= 3) << ' ' << (sumx > 2*maxn) << ' ' << ((countb >= 3) && (sumx > 2*maxn)) << endl;
		ans = ans % 998244353;
	}
	cout << ans << endl;
	return 0;
}
