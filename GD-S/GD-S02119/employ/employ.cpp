#include <bits/stdc++.h>
#define N 510
#define rint register int
#define ll unsigned long long
using namespace std;
const ll Mod = 998244353;

int n , m , num;
string s;
int c[N];
ll ans;
bool v[N];

void deal( int pos ){
	if( pos > n ){
		++ ans;
		return;
	}
	bool ctr=false;
	for( rint i=1; i <= n; ++i ){
		if( v[i] )	continue;
//		printf("%d ", i );
		if( s[pos-1]=='0' || n-num>=c[i] ){
			if( num == m )	continue;
			--num;
			ctr=true;
		}
		v[i] = true;
		deal( pos+1 );
		if( ctr ){
			++ num;
			ctr=false;
		}
		v[i] = false;
	}
}



int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	num = n;
	for( rint* i=c+1; i <= c+n; ++i )	cin >> *i;
	deal(1);
	printf("%llu", ans%Mod );
}
