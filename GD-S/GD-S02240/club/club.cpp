#include <bits/stdc++.h>
using namespace std;
long long n, m, sa, sb, sc, sum, ans, lenma;
long long a[10005], b[10005], c[10005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> n;
	for ( long long j = 1 ; j <= n ; j++ )
	{
		long long ma;
		long long h[10005] = {0};
		lenma = 0;
		cin >> m;
		sum = m / 2;
		ans = 0;
		sa = 0;
		sb = 0;
		sc = 0;
		for ( long long i = 1; i <= m ; i++ )
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		for ( long long i = m; i >= 1 ; i-- )
		{
			if ( a[i] != b[i] || a[i] != c[i] ){
				ma = max(a[i], b[i]);
				ma = max(ma, c[i]);
				if( ma == a[i] && sa < sum )
				{
					ma = a[i];
					sa ++; 
				}
				else
				{
					ma = max(b[i], c[i]);
					if ( ma == b[i] && sb < sum )
					{
						ma = b[i];
						sb ++;
					}
					else if ( sc < sum )
					{
						ma = c[i];
						sc ++;
					}
				}
			}
			else if ( a[i] == b[i] || a[i] == c[i] ){
				ma = max(a[i - 1], b[i - 1]);
				ma = max(ma, c[i - 1]);
				if( ma == a[i - 1] && sa < sum )
				{
					ma = a[i - 2];
					sa ++; 
				}
				else
				{
					ma = max(b[i - 1], c[i - 1]);
					if ( ma == b[i - 1] && sb < sum )
					{
						ma = b[i - 1];
						sb ++;
					}
					else if ( sc < sum )
					{
						ma = c[i - 1];
						sc ++;
					}
				}
				ma = max(a[i], b[i]);
				ma = max(ma, c[i]);
				if( ma == a[i] && sa < sum )
				{
					ma = a[i];
					sa ++; 
				}
				else
				{
					ma = max(b[i], c[i]);
					if ( ma == b[i] && sb < sum )
					{
						ma = b[i];
						sb ++;
					}
					else if ( sc < sum )
					{
						ma = c[i];
						sc ++;
					}
				}
			}
			long long len = 0, hh[10005]= {0}, maqq = ma, z = 0;
			while(ma)
			{
				ma /= 10;
				len ++;	
			}
			while(maqq)
			{
				hh[len - z - 1] = maqq % 10;
				z++;
				maqq /= 10;
			}
			lenma = max(lenma, len);
			for ( long long i = 0; i < lenma; i++ )
			{
				h[i] = h[i] + hh[i];
			}
			for ( long long i = lenma ; i >= 0; i-- )
			{
				if ( h[i] >= 10 )
				{
					h[i + 1] = h[i] / 10;
					h[i] %= 10;
					if ( h[lenma] ) lenma ++;
				}
			}
			if (h[lenma] == 0) lenma--;
		}
		for ( long long i = lenma; i >= 0; i-- )
		{
			cout << h[i];
		}
		cout <<" \n";
	}
	return 0;	
} 
