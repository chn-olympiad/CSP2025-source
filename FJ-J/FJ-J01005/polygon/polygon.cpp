#include <bits/stdc++.h>
using namespace std;
int n , a[10005] , sum[10005] , ans = 0 ;
int main()
{
	//freopen( "polygon.in" , "r" , stdin);
	//freopen( "polygon.out" , "w" , stdout);
	
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ )
	{
		cin >> a[i];
	}
	sort( a + 1 , a + n + 1 );
	for ( int i = 1 ; i <= n ;i ++ )
	{
		sum[i] = sum[i-1] + a[i];
	}
	for ( int i = n ; i >= 3 ; i --)
	{
		for ( int j = i - 1 ; j >= 2 ; j -- )
		{
			for ( int k = j - 1 ; k >= 1 ; k -- )
			{
				if ( a[j] + a[k] > a[i] )
				{
					ans ++ ; 
				}
			}
		}
	}
	for ( int l = n ; l >= 4 ; l -- )
	{
		for ( int i = l - 1  ; i >= 3 ; i --)
		{
			for ( int j = i - 1 ; j >= 2 ; j -- )
			{
				for ( int k = j - 1 ; k >= 1 ; k -- )
				{
					if ( a[j] + a[k] + a[i] > a[l] )
					{
						ans ++ ; 
					}
				}
			}
		}
	}
	for ( int s = n ; s >= 5 ; s -- )
	{
		for ( int l = s - 1 ; l >= 4 ; l -- )
		{
			for ( int i = l - 1  ; i >= 3 ; i --)
			{
				for ( int j = i - 1 ; j >= 2 ; j -- )
				{
					for ( int k = j - 1 ; k >= 1 ; k -- )
					{
						if ( a[j] + a[k] + a[i] + a[l] > a[s] )
						{
							ans ++ ; 
						}
					}
				}
			}
		}
	}
	for ( int d = n ; d >= 6 ; d -- )
	{
		for ( int s = d - 1 ; s >= 5 ; s -- )
		{
			for ( int l = s - 1 ; l >= 4 ; l -- )
			{
				for ( int i = l - 1  ; i >= 3 ; i --)
				{
					for ( int j = i - 1 ; j >= 2 ; j -- )
					{
						for ( int k = j - 1 ; k >= 1 ; k -- )
						{
							if ( a[j] + a[k] + a[i] + a[l] + a[s] > a[d] )
							{
								ans ++ ; 
							}
						}
					}
				}
			}
		}
	}
	for ( int y = n ; y >= 7 ; y -- )
	{
		for ( int d = y - 1  ; d >= 6 ; d -- )
		{
			for ( int s = d - 1 ; s >= 5 ; s -- )
			{
				for ( int l = s - 1 ; l >= 4 ; l -- )
				{
					for ( int i = l - 1  ; i >= 3 ; i --)
					{
						for ( int j = i - 1 ; j >= 2 ; j -- )
						{
							for ( int k = j - 1 ; k >= 1 ; k -- )
							{
								if ( a[j] + a[k] + a[i] + a[l] + a[s] + a[d] > a[y] )
								{
									ans ++ ; 
								}
							}
						}
					}
				}
			}
		}
	}
	for ( int x = n ; x >= 8 ; x -- )
	{
		for ( int y = x - 1  ; y >= 7 ; y -- )
		{	
			for ( int d = y - 1  ; d >= 6 ; d -- )
			{
				for ( int s = d - 1 ; s >= 5 ; s -- )
				{
					for ( int l = s - 1 ; l >= 4 ; l -- )
						{
						for ( int i = l - 1  ; i >= 3 ; i --)
						{
							for ( int j = i - 1 ; j >= 2 ; j -- )
							{
								for ( int k = j - 1 ; k >= 1 ; k -- )
								{
									if ( a[j] + a[k] + a[i] + a[l] + a[s] + a[d] + a[y] > a[x] )
									{
										ans ++ ; 
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for ( int c = n ; c >= 9 ; c -- )
	{
		for ( int x = c - 1  ; x >= 8 ; x -- )
		{
			for ( int y = x - 1  ; y >= 7 ; y -- )
			{	
				for ( int d = y - 1  ; d >= 6 ; d -- )
				{
					for ( int s = d - 1 ; s >= 5 ; s -- )
					{
						for ( int l = s - 1 ; l >= 4 ; l -- )
						{
							for ( int i = l - 1  ; i >= 3 ; i --)
							{
								for ( int j = i - 1 ; j >= 2 ; j -- )
								{
									for ( int k = j - 1 ; k >= 1 ; k -- )
									{
										if ( a[j] + a[k] + a[i] + a[l] + a[s] + a[d] + a[y] + a[x] > a[c] )
										{
											ans ++ ; 
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for ( int f = n ; f >= 10 ; f -- )
	{
		for ( int c = f - 1  ; c >= 9 ; c -- )
		{
			for ( int x = c - 1  ; x >= 8 ; x -- )
			{
				for ( int y = x - 1  ; y >= 7 ; y -- )
				{	
					for ( int d = y - 1  ; d >= 6 ; d -- )
					{
						for ( int s = d - 1 ; s >= 5 ; s -- )
						{
							for ( int l = s - 1 ; l >= 4 ; l -- )
							{
								for ( int i = l - 1  ; i >= 3 ; i --)
								{
									for ( int j = i - 1 ; j >= 2 ; j -- )
									{
										for ( int k = j - 1 ; k >= 1 ; k -- )
										{
											if ( a[j] + a[k] + a[i] + a[l] + a[s] + a[d] + a[y] + a[x] + a[c] > a[f] )
											{
												ans ++ ; 
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans ;
}
