#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, c = 1, r = 1, R;
int a[105];
bool flg = 1;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	R = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == R){
			cout << c << ' ' << r;
			return 0;
		}
		if((r == n || r == 1) && !flg){
			c++;	
			flg = 1;
		}else{
			flg = 0;
			if(c % 2) r++;
			else r--;			
		}
	}
	return 0;
}
