#include<bits/stdc++.h>
using namespace std;

int t, n;
int arr[100005][5];
int cnt[4];
bool visit[100005];
int mx = -1;

void dfs( int a, int sum ) {
	if( a == n ) {
		mx = max( mx, sum );
		return;
	}
	for( int i = 0; i < n; i++ ) {
		if( visit[i] == true ) continue;
		for( int j = 1; j <= 3; j++ ) {
			if( cnt[j] + 1 <= n / 2 ) {
				visit[i] = true;
				cnt[j] += 1;
				dfs( a + 1, sum + arr[i][j] );
				visit[i] = false;
				cnt[j] -= 1;
			}
		}
	}
}

int main(){
	freopen( "club.in", "r", stdin );
	freopen( "club.out", "w", stdout );
	
	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d", &n );
		for( int i = 0; i < 4; i++ ) {
			cnt[i] = 0;
		}
		mx = -1;
		for( int i = 0; i < n; i++ ) {
			scanf( "%d%d%d", &arr[i][1], &arr[i][2], &arr[i][3] );
		}
		dfs( 0, 0 );
		printf( "%d\n", mx );
	}
	
	return 0;
}
