#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int p = 998244353 , N = 505 ;
int n , m ;
int c[N] ;
bool b[N] ;
int a[N] ;
string s ;
bool check(int n)
{
	int p = 0 ;
	int l = 0 ;
	for(int i = 1 ; i < n ; i++)
	{
		if(l >= c[a[i]] || s[i - 1] == '0') l++ ;
		else
		{
			l = 0 ;
			p++ ;
		}
	}
	return (p >= m) ;
}
int ans = 0 ;
void print(int n)
{
	for(int i = 1 ; i < n ; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void dfs(int x)
{
//	cout<<x<<endl;
	if(x > n)
	{
//		if(check(x)) print(x) ;
		ans = (ans + check(x)) % p ;
		return ;
	}
	if(check(x))
	{
//		print(x) ;
		int s = 1 ;
		for(int i = x ; i <= n ; i++)
			s = s * (n - i + 1) % p ;
		ans = (ans + s) % p ;
		return ;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(b[i]) continue ;
		a[x] = i ;
		b[i] = 1 ;
		dfs(x + 1) ;
		b[i] = 0 ;
	}
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%*c",&n,&m) ;
	cin>>s;
	for(int i = 1 ; i <= n ; i++)
		scanf("%lld",&c[i]) ;
	dfs(1) ;
	printf("%lld",ans) ;
	return 0 ;
}
