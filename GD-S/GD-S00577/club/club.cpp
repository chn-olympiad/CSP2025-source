#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while( t-- ){
		int ans = 0;
		cin >> n;
		for( int i = 1;i <= n;i++ ){
			for( int j = 1;j <= 3;j++ ){
				cin >> a[i][j];
			}
		}
		if( n == 2 ){
			int maxn[5] = {0};
			cout << maxn[1] << ' ' << maxn[2] << ' ' << maxn[3] << ' ' << maxn[4] << ' ';
			if( a[1][1] > a[1][2] ){
				if( a[1][1] > a[1][3] ){
					maxn[1] = 1;
				}
				else{
					maxn[1] = 3;
				}
			}
			else{
				if( a[1][2] > a[1][3] ){
					maxn[1] = 2;
				}
				else{
					maxn[1] = 3;
				}
			}
			cout << maxn[1] << ' ' << maxn[2] << ' ' << maxn[3] << ' ' << maxn[4] << ' ';
			if( maxn[1] == 1 ){
				if( a[1][2] > a[1][3] ) maxn[2] = 2;
				else maxn[2] = 3;
			}
			else if( maxn[1] == 2 ){
				if( a[1][1] > a[1][3] ) maxn[2] = 1;
				else maxn[2] = 3;
			}
			else{
				if( a[1][1] > a[1][2] ) maxn[2] = 1;
				else maxn[2] = 2;
			}
			cout << maxn[1] << ' ' << maxn[2] << ' ' << maxn[3] << ' ' << maxn[4] << ' ';
			if( a[2][1] > a[2][2] ){
				if( a[2][1] > a[2][3] ) maxn[3] = 1;
				else maxn[3] = 3;
			}
			else{
				if( a[2][2] > a[2][3] ) maxn[3] = 2;
				else maxn[3] = 3;
			}
			if( maxn[3] == 1 ){
				if( a[2][2] > a[2][3] ) maxn[4] = 2;
				else maxn[4] = 3;
			}
			else if( maxn[3] == 2 ){
				if( a[2][1] > a[2][3] ) maxn[4] = 1;
				else maxn[4] = 3;
			}
			else{
				if( a[2][1] > a[2][2] ) maxn[4] = 1;
				else maxn[4] = 2;
			}
			if( maxn[1] == maxn[3] ){
				if( a[1][maxn[1]] > a[2][maxn[3]] ) ans = a[1][maxn[1]] + a[2][maxn[4]];
				else if( a[1][maxn[1]] < a[2][maxn[3]] ) ans = a[1][maxn[2]] + a[2][maxn[3]];
				else{
					if( a[1][maxn[2]] > a[2][maxn[4]] ) ans = a[1][maxn[2]] + a[2][maxn[3]];
					else ans = a[1][maxn[1]] + a[2][maxn[4]];
				}
			}
			else ans = a[1][maxn[1]] + a[2][maxn[3]];
			cout << maxn[1] << ' ' << maxn[2] << ' ' << maxn[3] << ' ' << maxn[4] << ' ';
		}
		else for( int i = 1;i <= n;i++ ) ans += max({a[i][1],a[i][2],a[i][3]});
		cout << ans;
	}
	return 0;
}
