#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
//	¼ÇµÃÈ¥×¢ÊÍ 
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (n < 3){
		cout << 0;
		return 0;
	}
	if (n == 3){
		if (max(max(a[1],a[2]),a[3]) * 2 < a[1] + a[2] + a[3]){
			cout << 1;
		}else cout << 0;
	}
	
	return 0;
} 
