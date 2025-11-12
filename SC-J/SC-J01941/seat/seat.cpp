#include<bits/stdc++.h>
using namespace std;
const int N = 2e2;
int n,m,a[N],ans[N][N],sum,idx;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	sum = a[1];
	sort( &a[1],&a[n*m] + 1 );
	reverse( &a[1],&a[n*m] + 1 );
	for(int i = 1;i <= m;i++){
		if( i % 2 ){
			for(int j = 1;j <= n;j++) ans[i][j] = a[++idx];
		}
		else{
			for(int j = n;j >= 1;j--) ans[i][j] = a[++idx];
		}
	}
	for(int i = 1;i <= m;i++){
		bool found = 0;
		for(int j = 1;j <= n;j++){
			if( ans[i][j] == sum ){
				cout << i << ' ' << j;
				found = 1;
				break;
			}
		}
		if( found ) break;
	}
	return 0;
}