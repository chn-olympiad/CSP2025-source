#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std ;
struct Node
{
	int fir, sec, thr, maxi, meci, mini ;
	int omax, omec, omin ;
} ;

const int N = 1e5 + 5 ;

int T, n, idx ;
Node a[N] ;

int tmp[4], pri[4] ;

int main()
{
	freopen("club.in", "r", stdin) ;
	freopen("club.out", "w", stdout) ;
	ios::sync_with_stdio(false) ;
	
	cin >> T ;
	while (T -- )
	{
		cin >> n, pri[1] = pri[2] = pri[3] = n + 1 ;
		for (int i = 1, maxi ; i <= n ; i ++ )
		{
			cin >> a[i].fir >> a[i].sec >> a[i].thr ;
			
			tmp[1] = a[i].fir, tmp[2] = a[i].sec, tmp[3] = a[i].thr ;
			sort(tmp + 1, tmp + 4) ;
			a[i].maxi = tmp[3], a[i].meci = tmp[2], a[i].mini = tmp[1] ;
			
			pri[1] -= (a[i].maxi == a[i].fir) ;
			pri[2] -= (a[i].maxi == a[i].sec) ;
			pri[3] -= (a[i].maxi == a[i].thr) ;
		}
		
		for (int i = 1 ; i <= n ; i ++ )
		{
			tmp[1] = a[i].fir * pri[1], tmp[2] = a[i].sec * pri[2], tmp[3] = a[i].thr * pri[3] ;
			sort(tmp + 1, tmp + 4) ;
			a[i].omax = tmp[3], a[i].omec = tmp[2], a[i].omin = tmp[1] ;
		}
		
		/*
		1.最大值排序> 
		排序人时如果最大值相同,
		1.1.按照次大值排序<
		1.2.如果还相同，按照最小值排序<
		xxx
		1.按照权值排序 
		*/
		sort(a + 1, a + n + 1, [&](const Node& u, const Node& v)
		{
			if (u.omax == v.omax)
			{
				if (u.omec == v.omec)
					return u.omin > v.omin ;
				return u.omec > v.omec ;
			}
			return u.omax > v.omax ;
		}) ;
		
		int cur[4] = {0}, res = 0 ;
		for (int i = 1 ; i <= n ; i ++ )
		{
			int maxClub = 0, mecClub = 0, minClub = 0 ;
			if (a[i].maxi == a[i].fir) maxClub = 1 ;
			else if (a[i].maxi == a[i].sec) maxClub = 2 ;
			else if (a[i].maxi == a[i].thr) maxClub = 3 ;
			if (a[i].meci == a[i].fir) mecClub = 1 ;
			else if (a[i].meci == a[i].sec) mecClub = 2 ;
			else if (a[i].meci == a[i].thr) mecClub = 3 ;
			if (a[i].mini == a[i].fir) minClub = 1 ;
			else if (a[i].mini == a[i].sec) minClub = 2 ;
			else if (a[i].mini == a[i].thr) minClub = 3 ;
						
			if (cur[maxClub] + 1 > n / 2)
			{
				if (cur[mecClub] + 1 > n / 2)
					cur[minClub] ++ , res += a[i].mini ;
				else cur[mecClub] ++ , res += a[i].meci ;
			}
			else cur[maxClub] ++ , res += a[i].maxi ;
		}
		
		cout << res << '\n' ;
	}
	
	return 0 ;
}
