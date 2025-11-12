#include<iostream>
#include<algorithm>
using namespace std;

#define int long long
#define N 100005

int arr[N][5], cnt[5], num[N][5], brr[N];
signed main()
{
	ios::sync_with_stdio( false );
	cin.tie( 0 ), cout.tie( 0 );
	freopen( "club.in", "r", stdin );
	freopen( "club.out", "w", stdout );
	int T = 0;
	cin >> T;
	while( T -- )
	{
		int n = 0, ans = 0, now = 0;
		cin >> n;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for ( int i = 1; i <= n; i ++ ) cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
		for ( int i = 1; i <= n; i ++ )
		{
			for ( int j = 1; j <= 3; j ++ )
			{
				if ( arr[i][j] == max( arr[i][1], max( arr[i][2], arr[i][3] ) ) ) 
				{
					ans += arr[i][j], num[++cnt[j]][j] = i;
					if ( cnt[j] > n / 2 ) now = j;
					break;
				}
			}
		}
		if ( ( cnt[1] <= n / 2 ) && ( cnt[2] <= n / 2 ) && ( cnt[3] <= n / 2 ) ) 
		{
			cout << ans << endl;
			continue;
		}
		for ( int t = 1; t <= cnt[now]; t ++ )
		{
			int i = num[t][now];
			int maxx = max( arr[i][1], max( arr[i][2], arr[i][3] ) ), minn = min( arr[i][1], min( arr[i][2], arr[i][3] ) ), mid = arr[i][1] + arr[i][2] + arr[i][3] - maxx - minn;
			brr[t] = maxx - mid;
		}
		sort( brr+1, brr+1+cnt[now] );
		for ( int i = 1; i <= cnt[now] - n/2; i ++ ) ans -= brr[i];
		cout << ans << endl;
	}
	return 0;
}