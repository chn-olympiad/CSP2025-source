#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105 ;
int a[N] ,g[15][15];
bool cmp(int x, int y) {
	return y < x;
}
signed main() {
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0) ;
	int n ,m;
	cin >> n>> m;
	for(int i= 1;i <= n * m;i ++)  
		cin >> a[i] ;
	int x = a[1] ;
	sort(a+1, a+1 + n*m ,cmp) ;
	int now = 1;
	for(int i=1 ;i <= n;i ++) {
		if(i % 2 == 0) {
			for(int j =m;j >= 1;j --){
				g[i][j] = a[now] ;
				now ++;
			}
		}else {
			for(int j = 1;j <= m;j ++){
				g[i][j] = a[now] ;
				now ++;
			}
		}
	}
	for(int i=1;i <= n;i ++) {
		for(int j=1;j <= m;j ++) 
		if(g[i][j] == x) {
			cout << i << " " << j; 
			return 0;
		}
		
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4