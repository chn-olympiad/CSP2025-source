#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 10 ;
int n , k ;
int a[N] ;
int check(int mid)
{
	int lm = mid ;
	int lmi = 1 ;
	int cnt = 0 ;
	int i = 1 ;
	while(i <= n)
	{
		if(a[i] == k) 
		{
			cnt ++ , i ++ ;
			continue ;
		}	
		int sum = a[i] ;
		bool f = false ;
		for(int j = i + 1 ; j <= i + 1 + lm ; j ++)
		{
			//cout << i << ' ' << (sum ) << endl ;
			sum = (sum ^ a[j]) ;
			if(sum == k)
			{
			//	cout << sum << ' ' << i << ' ' << j << endl; 
				cnt ++ ;
				 i = j + 1 ;
				 f = true ;
				break ;
			}
		}
		if(f == false) i ++ ;
	} 
	return cnt ;
}
int main()
{
	freopen("xor.in" , "r" , stdin) ;
	freopen("xor.out" , "w" , stdout) ;
	cin >> n >> k ;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i] ;
	}
	int l = 0 , r = n , maxx = 0 ;
	for(int i = 1 ; i <= n ; i ++)
	{
		int op = check(i) ;
		maxx = max(maxx , op) ;
	}
	cout << maxx ;
	return 0 ;
}