#include<iostream>
#include<algorithm>
using namespace std;

#define int long long
#define N 5000005
#define mod1 1000000007
#define mod2 100003

int n, q, pos[N], tab1[N], tab2[N], pre1[N], pre2[N], olen[N];
pair<int, int> ori[N], dif[N];
inline pair<int, int> hashh( string str )
{
	int len = str.length(), ans1 = 0, ans2 = 0;
	for ( int i = 0; i < len; i ++ ) 
	{
		int val = str[i] - 'a';
		if ( str[i] == '&' ) val = 26;
		if ( str[i] == '?' ) val = 27;
		ans1 = ( ans1 * 28 % mod1 + val ) % mod1;
		ans2 = ( ans2 * 28 % mod2 + val ) % mod2;
	}
	return make_pair( ans1, ans2 );
}
inline pair<string, int> get_ori( string str1, string str2 )
{
	string st1, st2, ans;
	int len = str1.length();
	for ( int i = 0; i < len; i ++ )
	{
		if ( str1[i] == str2[i] ) st1 += '&', st2 += '&';
		else st1 += str1[i], st2 += str2[i];
	}
	int fir = 0, las = 0;
	for ( int i = 0; i < len; i ++ )
	{
		if ( st1[i] != '&' ) 
		{
			fir = i + 1;
			break;
		}
	}
	for ( int i = len - 1; i >= 0; i -- )
	{
		if ( st1[i] != '&' ) 
		{
			las = i + 1;
			break;
		}
	}
	for ( int i = fir-1; i < las; i ++ ) ans += st1[i];
	ans += '?';
	for ( int i = fir-1; i < las; i ++ ) ans += st2[i];
	return make_pair( ans, fir );
}
void init()
{
	tab1[0] = tab2[0] = 1;
	for ( int i = 1; i <= 500005; i ++ )
	{
		tab1[i] = tab1[i-1] * 28 % mod1;
		tab2[i] = tab2[i-1] * 28 % mod2;
	}
}
signed main()
{
//	system( "fc replace.out replace3.ans" );
	ios::sync_with_stdio( false );
	cin.tie( 0 ), cout.tie( 0 );
	freopen( "replace.in", "r", stdin );
	freopen( "replace.out", "w", stdout );
	init();
	cin >> n >> q;
	for ( int i = 1; i <= n; i ++ )
	{
		string str1, str2;
		cin >> str1 >> str2;
		auto res = get_ori( str1, str2 );
//		cout << res.first << endl;
		pos[i] = res.second, olen[i] = str1.length();
		dif[i] = hashh( res.first );
		ori[i] = hashh( str1 );
	}
	while( q -- )
	{
		string str1, str2;
		cin >> str1 >> str2;
		if ( str1.length() != str2.length() )
		{
			cout << 0 << "\n";
			continue;
		}
		auto res = get_ori( str1, str2 );
		auto nowdif = hashh( res.first );
		int nowpos = res.second, len = str1.length();
		for ( int i = 0; i < str1.length(); i ++ )
		{
			pre1[i+1] = ( pre1[i] * 28 + str1[i] -'a' ) % mod1;
			pre2[i+1] = ( pre2[i] * 28 + str1[i] -'a' ) % mod2;
		}
		int ans = 0;
		for ( int i = 1; i <= n; i ++ )
		{
			if ( nowdif.first == dif[i].first && nowdif.second == dif[i].second )
			{
				int beg = nowpos - pos[i] + 1;
				if ( beg < 1 || beg + olen[i] - 1 > len ) continue;
				int all1 = ( pre1[beg+olen[i]-1] - tab1[olen[i]] * pre1[beg-1] % mod1 + mod1 ) % mod1;
				int all2 = ( pre2[beg+olen[i]-1] - tab2[olen[i]] * pre2[beg-1] % mod2 + mod2 ) % mod2;
				if ( all1 == ori[i].first && all2 == ori[i].second ) ans ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}