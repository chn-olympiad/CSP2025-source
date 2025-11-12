#include<bits/stdc++.h>
#define def(i,a,b) for(int i=a;i<=b;i++)
#define udef(i,a,b) for(int i=a;i>=b;i--)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define m(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
using namespace std;
typedef int i32;
typedef long long i63;
const int N = 5e2 + 5, INF = 0x3f3f3f3f,mod = 998244353;
i32 n,m,nn,g;
string s;
i32 a[N];
void work()
{
	i63 ans = 1;
	def(i,1,nn)
		ans = (ans * i) % mod;
	def(i,1,g)
		ans = (ans * i) % mod;
	cout <<	ans  << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cout << 1 << '\n';
	cin >> n >> m;
	nn = n,g = 0;
	cin >> s;
	s = " " + s;
	def(i,1,n)
	{
		cin >> a[i];
	}
	if(s.find("0") != -1) cout << 0 << '\n';
	else work(); 
	return 0;
}

