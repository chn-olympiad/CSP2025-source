#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x > y;
}
int main(){
//	¼ÇµÃÈ¥×¢ÊÍ 
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m,r,x = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
//	for (int i = 1; i <= n * m; i++) cout << a[i] << " ";
	for (int i = 1; i <= n * m; i++){
		if (a[i] == r){
			x = i;
			break;
		}
	}
//	cout << x;
	if (x % n != 0){
		if ((x / n + 1) % 2 == 0){
			cout << x / n + 1 << " " << m - x % n + 1;
			return 0;
		}else{
			cout << x / n + 1 << " " << x % n;
			return 0;
		}
	}else{
		cout << x / n << " " << n;
	}
	return 0;
} 
