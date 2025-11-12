#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 10 ;
int n ;
int a[N][3] ;
int id[N] ;
int max(int a , int b)
{
	return a > b ? a : b ;
}
bool cmpa(int x , int y)
{
	return a[x][0] - max(a[x][1],a[x][2]) > a[y][0] - max(a[y][1],a[y][2]) ;
}
bool cmpb(int x , int y)
{
	return a[x][1] - max(a[x][0],a[x][2]) > a[y][1] - max(a[y][0],a[y][2]) ;
}
bool cmpc(int x , int y)
{
	return a[x][2] - max(a[x][1],a[x][0]) > a[y][2] - max(a[y][1],a[y][0]) ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t ;
	scanf("%d",&t) ;
	while(t--)
	{
		scanf("%d",&n) ;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 0 ; j < 3 ; j++)
				scanf("%d",&a[i][j]) ;
		int a1 = 0 , b1 = 0 , c1 = 0 ;
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i++)
		{
			int x = a[i][0] , y = a[i][1] , z = a[i][2] ;
			int w = max(x,max(y,z)) ;
			ans += w ;
			if(w == x) a1++ ;
			else if(w == y) b1++ ;
			else c1++ ;
		}
		int l = 0 ;
		if(a1 > n / 2)
		{
			for(int i = 1 ; i <= n ; i++)
			{
				int x = a[i][0] , y = a[i][1] , z = a[i][2] ;
				int w = max(x,max(y,z)) ;
				if(w == x) id[++l] = i ;
			}
			sort(id + 1,id + 1 + l,cmpa) ;
			for(int i = n / 2 + 1 ; i <= l ; i++)
				ans = ans - a[id[i]][0] + max(a[id[i]][1],a[id[i]][2]) ;
		}
		if(b1 > n / 2)
		{
			for(int i = 1 ; i <= n ; i++)
			{
				int x = a[i][0] , y = a[i][1] , z = a[i][2] ;
				int w = max(x,max(y,z)) ;
				if(w == y) id[++l] = i ;
			}
			sort(id + 1,id + 1 + l,cmpb) ;
			for(int i = n / 2 + 1 ; i <= l ; i++)
				ans = ans - a[id[i]][1] + max(a[id[i]][0],a[id[i]][2]) ;
		}
		if(c1 > n / 2)
		{
			for(int i = 1 ; i <= n ; i++)
			{
				int x = a[i][0] , y = a[i][1] , z = a[i][2] ;
				int w = max(x,max(y,z)) ;
				if(w == z) id[++l] = i ;
			}
			sort(id + 1,id + 1 + l,cmpc) ;
			for(int i = n / 2 + 1 ; i <= l ; i++)
				ans = ans - a[id[i]][2] + max(a[id[i]][1],a[id[i]][0]) ;
		}
		printf("%d\n",ans) ;
	}
	return 0 ;
}
