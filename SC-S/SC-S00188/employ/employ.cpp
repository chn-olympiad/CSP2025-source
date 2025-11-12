#include<iostream>
#include<algorithm>
using namespace std;

#define int long long
#define N 505
#define mod 998244353

int n, m, arr[N], p[N], dp[20][250000];
pair<int, int> st[1000005];
string str;
void solve1()
{
	int ans = 0;
	for ( int i = 1; i <= n; i ++ ) p[i] = i;
	do 
	{
		int rej = 0;
		for ( int i = 1; i <= n; i ++ )
		{
			if ( rej >= arr[p[i]] )
			{
				rej ++;
				continue;
			}
			if ( str[i-1] == '0' ) rej ++;
		}
		if ( n - rej >= m ) ans ++;
		
	}while( next_permutation( p+1, p+1+n ) );
	cout << ans << endl;
}
int get_num( int x )
{
	int cnt = 0;
	while( x ) cnt += ( x & 1 ), x >>= 1;
	return cnt;
}
void solve2()
{
	for ( int i = 0; i < ( 1 << (n) ); i ++ )
	{
		st[i+1].first = get_num( i ), st[i+1].second = i;
	}
	sort( st+1, st+1+(1<<n)-1 );
	for ( int i = 2; i < ( 1 << n ); i ++ )
	{
//		cout << st[i].first << " " << st[i].second << endl;
		if ( st[i].first == 1 )
		{
			for ( int j = 1; j <= n; j ++ )
			{
				if ( ( ( 1 << ( j-1 ) ) & st[i].second ) != 0 )
				{
					if ( arr[j] != 0 && str[0] == '1' ) dp[0][st[i].second] = 1;
					else dp[1][st[i].second] = 1;
//					cout << dp[0][st[i].second] << endl;
				}
			}
		}
		for ( int j = 0; j <= st[i].first; j ++ )
		{
			if ( dp[j][st[i].second] == 0 ) continue;
			for ( int k = 1; k <= n; k ++ )
			{
				if ( ( ( 1 << ( k-1 ) ) & st[i].second ) != 0 ) continue;
				if ( arr[k] <= j )
				{
					dp[j+1][st[i].second|(1<<(k-1))] += dp[j][st[i].second], dp[j+1][st[i].second|(1<<(k-1))] %= mod;
					continue;
				}
//				cout << st[i].first << "qwq\n";
				if ( str[st[i].first] == 0 ) dp[j+1][st[i].second|(1<<(k-1))] += dp[j][st[i].second], dp[j+1][st[i].second|(1<<(k-1))] %= mod;
				else dp[j][st[i].second|(1<<(k-1))] += dp[j][st[i].second], dp[j][st[i].second|(1<<(k-1))] %= mod;
				
			}
		}
	}
	int ans = 0;
	for ( int i = 0; i <= n-m; i ++ )
	{
		ans += dp[i][(1<<n)-1], ans %= mod;
	}
	cout << ans << endl;
}
signed main()
{
	freopen( "employ.in", "r", stdin );
	freopen( "employ.out", "w", stdout );
	cin >> n >> m;
	cin >> str;
	for ( int i = 1; i <= n; i ++ ) cin >> arr[i];
//	bool flag = 1;
//	for ( int i = 1; i <= n; i ++ )
//	{
//		if ( str[i-1] == '0' )
//		{
//			flag = 0;
//			break;
//		}
//	}
//	if ( flag ) solve2();
	if ( n <= 19 ) solve1();
	else solve2();
	return 0;
}