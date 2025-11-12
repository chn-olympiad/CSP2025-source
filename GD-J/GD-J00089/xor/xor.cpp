#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std ;

const int N = 1e3 + 5 ;

int n, k, res, a[N], S[N] ;
int cnt[N][20] ;

int tmp[20] ;
void preInit(int x, int tmp[])
{
	for (int i = 0 ; i < 20 ; i ++ )
		tmp[i] = cnt[n][i] - cnt[x - 1][i] ;
}

bool check(int x)
{
	preInit(x, tmp) ;
	for (int bit = 0 ; bit < 20 ; bit ++ )
		if (((k >> bit) & 1) && !tmp[bit])
			return false ;
		else if (!((k >> bit) & 1) && ((a[x] >> bit) & 1) && tmp[bit] == 1)
			return false ;
	return true ;
}

int main()
{
	freopen("xor.in", "r", stdin) ;
	freopen("xor.out", "w", stdout) ;
	
	cin >> n >> k ;
	for (int i = 1, x, j ; i <= n ; i ++ )
	{
		cin >> a[i], S[i] = S[i - 1] ^ a[i] ;
		
		x = a[i], j = 0 ;
		while (x)
		{
			if (x & 1) cnt[i][j] ++  ;
			x >>= 1, j ++  ;
		}
		
		for (int k = 0 ; k < 20 ; k ++ )
			cnt[i][k] += cnt[i - 1][k] ;
	}
	
	
	for (int i = 1, j = 1 ; i <= n ; i = j)
	{
		if (!check(i))
		{
			i ++ , j = i ;
			continue ;
		}
		bool flag = false ;
		while (j <= n)
		{
			if ((S[j] ^ S[i - 1]) == k)
			{
				flag = true ;
				break ;
			}
			j ++  ;
		}
		res += flag, j += flag, i = j ;
	}
	
	cout << res << '\n' ;
	
	return 0 ;
}
