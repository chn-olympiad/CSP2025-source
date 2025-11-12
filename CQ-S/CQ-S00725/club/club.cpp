#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int t;

struct node{
	int m, i, c;
}s[N];

bool cmp ( node x, node y ) {
	return x.m >= y.m;
}

int main() {
	freopen( "club.in", "r", stdin );
	freopen( "club.out", "w", stdout );
	cin >> t;
	while ( t-- ) {
		int n, ans = 0, cnt = 0, a = 0, b = 0, c = 0;
		bool vis[N] = {};
		cin >> n;
		for ( int i = 1; i <= 3 * n; i += 3 ) {
			cin >> s[i].m >> s[i + 1].m >> s[i + 2].m;
			s[i].i = s[i + 1].i = s[i + 2].i = i / 3 + 1;
			s[i].c = 1, s[i + 1].c = 2, s[i + 2].c = 3;
		}
		sort( s + 1, s + 3 * n + 1, cmp );
		for ( int i = 1; i <= 3 * n; i++ ) {
			cout << "\n" << s[i].m << " " << s[i].i << " " << s[i].c;
			if ( cnt > n ) break;
			if ( !vis[s[i].i] ) {
				if ( s[i].c == 1 ) {
					if ( a >= ( n / 2 ) ) continue;
					else a++;
				}else if ( s[i].c == 2 ) {
					if ( b >= ( n / 2 ) ) continue;
					else b++;
				}else if ( s[i].c == 3 ) {
					if ( c >= ( n / 2 ) ) continue;
					else c++;
				}
				cnt++;
				ans += s[i].m;
				vis[s[i].i] = 1;
			}
		}
		cout << ans << "\n";
	}
	fclose( stdin );
	fclose( stdout );
	return 0;
}
