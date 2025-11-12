#include<iostream>
#include<algorithm>
using namespace std;

#define int long long
#define N 1000005

int n, m, k;
struct node
{
	int from;
	int to;
	int val;
}g[N*4];
int num = 0, head[N], c[15], arr[15][N], fat[N];
int fid( int x )
{
	return fat[x] == x ? x : fat[x] = fid( fat[x] );
}
void merge( int x, int y )
{
	fat[fid(x)] = fid( y );
}
bool cmp( node s1, node s2 )
{
	return s1.val < s2.val;
}
signed main()
{
	ios::sync_with_stdio( false );
	cin.tie( 0 ), cout.tie( 0 );
	freopen( "road.in", "r", stdin );
	freopen( "road.out", "w", stdout );
	cin >> n >> m >> k;
	for ( int i = 1; i <= n; i ++ ) fat[i] = i;
	for ( int i = 1; i <= m; i ++ )
	{
		cin >> g[i].from >> g[i].to >> g[i].val;
	}
	num = m;
	for ( int i = 1; i <= k; i ++ )
	{
		cin >> c[i];
		int now = 0;
		for ( int j = 1; j <= n; j ++ )
		{
			cin >> arr[i][j];
			if ( arr[i][j] == 0 ) now = j;
		}
//		cout << now << endl;
		for ( int j = 1; j <= n; j ++ )
		{
			if ( arr[i][j] == 0 ) continue;
			g[++num] = { now, j, arr[i][j] };
		}
	}
	sort( g+1, g+1+num, cmp );
	int ans = 0, cnt = 0;
	for ( int i = 1; i <= num; i ++ )
	{
		if ( cnt == n - 1 ) break;
		if ( fid( g[i].from ) == fid( g[i].to ) ) continue;
		merge( g[i].from, g[i].to );
		ans += g[i].val, cnt ++;
	}
	cout << ans << endl;
	return 0;
}