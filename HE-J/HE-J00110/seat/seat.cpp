#include <bits/stdc++.h>
using namespace std;
int n , m , l = 1 , r = 1;
int a[105];
bool cmp(int x , int y){
	return x > y;
}
int main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n * m ; i++) cin >> a[i];
	int xiaoming = a[1];
	sort(a + 1 , a + 1 + n * m , cmp);
	for (int i = 1 ; i <= n * m ; i++){
		if (a[i] == xiaoming){
			cout << l << " " << r;
			return 0;
		}
		if (l % 2 != 0){
			if (r == m)
				l++;
			else r++;
		}
		else{
			if (r == 1)
				l++;
			else r--;
		}
	}
	return 0;
}
