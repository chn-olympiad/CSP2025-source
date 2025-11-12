#include<bits/stdc++.h>
#define F(i,a,b) for( int i=a; i<=b; i++)
#define FF(i,a,b) for ( int i=a; i>=b; i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define emb(x) emplace_back(x)
const int MAXN =1e5+5;

using namespace std;
int n,m,c[MAXN];
string s;

void solve() {
	cin >>n >>m >>s;
	F ( i,1,n) cin >>c[i];
	cout <<rand() <<'\n';
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(int(time(0)));
	
	solve();
	
	return 0;
}
/****

****/
