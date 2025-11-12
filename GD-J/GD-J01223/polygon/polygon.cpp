#include <bits/stdc++.h>
using namespace std;
int n , l[5005] , a[5005] , sum , ans , cnt = 1;
int main()
{
   freopen("polygon.in" , "r" , stdin);
   freopen("polygon.out" , "w" , stdout);
   cin >> n; 
   for(int i = 1; i <= n;i++)
   {
   	    cin >> l[i];
   }
   sort(l + 1 , l + n + 1);
   for(int j = n; j >= 1; j--)
   {
   	  for(int i = 1; i < j; i++)
   	  {
   	  	sum += l[i];
   	  	cnt++; 
   	  	if(sum > l[j] && cnt >= 3)
   	  	{
   	  		ans++;
	    }
	  }
	  cnt = 1;
   }
   cout << ans % 998244353;
   return 0;	
} 
