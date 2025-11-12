#include <bits/stdc++.h>
#define N 200010
#define rint register int
#define ll unsigned long long
using namespace std;
const ll Mod = 998244353;

int n , q;
string s[N][2] , qus[N][2];
int c[N];
ll ans;
bool v[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for( rint i=1; i <= n; ++i )	cin >> s[i][0] >> s[i][1];
	for( rint i=1; i <= q; ++i ){
		cin >> qus[i][0] >> qus[i][1];
		for( rint j=1; j <= n; ++j )
			if( s[j][0]==qus[j][0] && s[i][1]==qus[i][1] )	++ans;
		printf("%llu\n", ans );
		ans = 0;
	}	
}
