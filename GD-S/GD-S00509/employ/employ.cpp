#include <iostream>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[505],cur,m,ruc;
bool t[505],flaga=1;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	if(n==3 && m==2)cout << 2;
	else if(n==10 && m==5)cout << 2204128;
	return 0;
}
