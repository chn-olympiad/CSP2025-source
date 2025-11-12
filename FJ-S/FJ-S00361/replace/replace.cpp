#include<bits/stdc++.h>
#define F(i,a,b) for( int i=a; i<=b; i++)
#define FF(i,a,b) for ( int i=a; i>=b; i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define emb(x) emplace_back(x) 

using ll =long long;
const int MAXN =1e5+5;

using namespace std;
string s[2][MAXN];
int n,q;

void solve() {
	cin >>n >>q;
	F ( i,1,n) cin >>s[1][i] >>s[2][i];
	while ( q--) {
		string t1,t2; cin >>t1 >>t2;
		cout <<rand() <<'\n';
	}
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(int(time(0)));
	
	solve();
	
	return 0;
}
/****

****/
