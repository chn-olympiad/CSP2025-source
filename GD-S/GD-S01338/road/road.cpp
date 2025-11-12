#include <iostream> 
#include <algorithm>
using namespace std ;

const int N = 1e6+5 ;
int n , m , k , c[11][N] , sum , sum1 ;
long long ans ;
bool fl[N] ;

struct code
{
	int u , v , w ;
	bool operator < (const code &x) const
	{
		return w < x.w ;
	}
}	s[N] ;

int main()
{
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m >> k ;
	for (int i = 1 ; i <= m ; i++)
	{
		cin >> s[i].u >> s[i].v >> s[i].w ;
	}
	for (int i = 1 ; i <= k ; i++)
	{
		for (int j = 0 ; j <= n ; i++)
		{
			cin >> c[i][j] ;
			if (!c[i][j] && !j) sum1++ ;
		}
	}
	sort(s+1,s+m+1) ;
	if (sum1 == k)//A¼Æ»®
	{
		for (int i = 1 ; i <= k ; i++)
		{
			int x = 0 , y = 0 ;
			for (int j = 1 ; j <= n ; i++)
			{
				if (!c[i][j])
				{
					x++ ; ;
					if (x == 1)
					{
						y = j ;
					}
					else
					{
						fl[y] = fl[j] = 1 ;
					}
					
				}
			}
			if(x!=1)	sum += x ;
		}
		for (int i = 1 ; i <= m ; i++)
		{
			if ( (fl[s[i].u] && !fl[s[i].v]) || (!fl[s[i].u] && fl[s[i].v]) )
			{
				ans += s[i].w ;
				sum++ ;
				fl[s[i].u] = fl[s[i].v] = 1 ;
			}
			if (sum == n) break ;
		}
		cout << ans ;
	} 
	return 0 ;
}
