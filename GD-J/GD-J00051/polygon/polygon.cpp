#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int p = 998244353 , N = 5e3 + 10 ;
int a[N] ;
int g[N] ;
queue<int> q , q1 ;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n ;
	scanf("%lld",&n) ;
	for(int i = 1 ; i <= n ; i++)
		scanf("%lld",&a[i]) ;
	sort(a + 1,a + 1 + n) ;
	if(a[n] == 1 && n > 60)
	{
		g[0] = 1 ;
		for(int i = 1 ; i <= n ; i++)
			g[i] = g[i - 1] * i % p ;
		int ans = 0 ;
		for(int i = 3 ; i <= n ; i++)
		{
			int s = n ;
			for(int j = 1 ; j < i ; j++)
				s = s * (n - j) % p ;
			ans = (ans + s) % p / g[i] % p ;
		}
		printf("%lld",ans) ;
		return 0 ;
	}
	int ans = 0 ;
	q.push(0) ;
	q.push(a[1]) ;
	for(int i = 2 ; i < n ; i++)
	{
		while(q.size())
		{
			int s = q.front() ;
			q.pop() ;
			q1.push(s) ;
			q1.push(s + a[i]) ;
			if(s + a[i] > a[i + 1])
			{
//				cout<<s + a[i]<<" ";
				int l = i + 1 , r = n ;
				while(l < r)
				{
					int mid = (l + r + 1) / 2 ;
					if(s + a[i] > a[mid]) l = mid ;
					else r = mid - 1 ;
				}
				ans = (ans + l - i) % p ;
			}
		}
		while(q1.size())
		{
			q.push(q1.front()) ;
			q1.pop() ;
		}
//		cout<<endl;
	}
	printf("%lld",ans) ;
	return 0 ;
}
