#include <iostream> 
#include <queue>
using namespace std ;

const int N = 1e5+5 ;
int T , n , q ;

struct code
{
	int a1 , a2 , a3 ;
}	s[N] , x ;

struct code1
{
	int a1 , a2 , a3 ;
	operator < (const code1 &x) const
    { return max(a1-a3,a1-a2) < max(x.a1 - x.a2,x.a1 - x.a3) ; }
} ;

struct code2
{
	int a1 , a2 , a3 ;
	operator < (const code2 &x) const
    { return max(a2-a3,a2-a1) < max(x.a2 - x.a1,x.a2 - x.a3) ; }
} ;

struct code3
{
	int a1 , a2 , a3 ;
	operator < (const code3 &x) const
    { return max(a3-a1,a3-a2) < max(x.a3 - x.a2,x.a3 - x.a1) ; }
} ;

int main()
{
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> T ;
	while(T--)
	{
		cin >> n ;
		long long ans = 0 ;
		priority_queue <code1> d1;
		priority_queue <code2> d2;
		priority_queue <code3> d3;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> s[i].a1 >> s[i].a2 >> s[i].a3 ;
			
			x = {0,0,0} ;
			
			if (s[i].a1 >= s[i].a2 && s[i].a1 >= s[i].a3 )
			{
				d1.push({ -s[i].a1 , -s[i].a2 , -s[i].a3 }) ;
				continue ;
			}
			if (s[i].a2 >= s[i].a1 && s[i].a2 >= s[i].a3 )
			{
				d2.push({ -s[i].a1 , -s[i].a2 , -s[i].a3 }) ;
				continue ;
			}
			if (s[i].a3 >= s[i].a2 && s[i].a3 >= s[i].a1 )
			{
				d3.push({ -s[i].a1 , -s[i].a2 , -s[i].a3 }) ;
				continue ;
			}
		}
		
		while (d1.size() > n/2)
		{
			x = { -d1.top().a1 , -d1.top().a2 , -d1.top().a3 } ;
			d1.pop() ; 
			if (x.a1 - x.a2 < x.a1 - x.a3 )
			{
				d2.push({ -x.a1 , -x.a2 , -x.a3 }) ;
				continue ;
			}
			else
			{
				d3.push({ -x.a1 , -x.a2 , -x.a3 }) ;
				continue ;
			}
		}
		
		while (d2.size() > n/2)
		{
			x = { -d2.top().a1 , -d2.top().a2 , -d2.top().a3 } ;
			d2.pop() ; 
			if (x.a2 - x.a1 < x.a2 - x.a3)
			{
				d1.push({ -x.a1 , -x.a2 , -x.a3 }) ;
				continue ;
			}
			else
			{
				d3.push({ -x.a1 , -x.a2 , -x.a3 }) ;
				continue ;
			}
		}
		
		while (d3.size() > n/2)
		{
			x = { -d3.top().a1 , -d3.top().a2 , -d3.top().a3 } ;
			d3.pop() ; 
			if (x.a3 - x.a2 < x.a3 - x.a1)
			{
				d2.push({ -x.a1 , -x.a2 , -x.a3 }) ;
				continue ;
			}
			else
			{
				d1.push({ -x.a1 , -x.a2 , -x.a3 }) ;
				continue ;
			}
		}
		
		while (!d1.empty())
		{
			ans += d1.top().a1 ;
			cout << d1.top().a1 << ' ' ;
			d1.pop() ;
		}
		cout << endl ;
		while (!d2.empty())
		{
			ans += d2.top().a2 ;
			cout << d2.top().a2 << ' ' ;
			d2.pop() ;
		}
		cout << endl ;
		while (!d3.empty())
		{
			ans += d3.top().a3 ;
			cout << d3.top().a3 << ' ' ;
			d3.pop() ;
		}
		cout << endl ;
		cout << -ans << endl ;
	}
	return 0 ;
}


