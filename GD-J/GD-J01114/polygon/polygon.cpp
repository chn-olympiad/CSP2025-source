#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool flag = 1;
	int sum = 0;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		sum += a[i];
	}
	if (n == 3){
		int maxn = max(a[1],max(a[2],a[3]));
		if (maxn * 2 < sum)cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}else if(n <= 2)cout << 0 << endl;
	return 0;
}
