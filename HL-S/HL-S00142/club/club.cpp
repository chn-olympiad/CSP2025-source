#include <bits/stdc++.h>
using namespace std ;
int t , n , a[100005][5] ;
struct myd
{
	int i , p , v ;
};
myd l[100005] ;
int ans[100005] ; 
int AA[10000005] ;
bool cmp( myd x , myd y )
{
	return x.v > y.v ;
}

int dfs( int p , int v1 , int v2 , int v3 , int val )
{
	if ( p == n ) return val ;
	int x = 0 , y = 0 , z = 0 ;
	if ( v1 < n/2 ) x = dfs(p+1,v1+1,v2,v3,val+a[p][0]) ;
	if ( v2 < n/2 ) y = dfs(p+1,v1,v2+1,v3,val+a[p][1]) ;
	if ( v3 < n/2 ) z = dfs(p+1,v1,v2,v3+1,val+a[p][2]) ;
	return max(max(x,y),z);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while ( t -- )
	{
		scanf("%d",&n);
		memset(ans,-1,sizeof(ans));
		int top = 0 ;
		int A = 0 , topA = 0 ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			int mn = min(min(a[i][0],a[i][1]),a[i][2]);
			if ( a[i][1] == 0 && a[i][2] == 0 ) A ++ ;
			AA[topA++] = a[i][0] ;
			l[top++] = {i,0,a[i][0]-mn} ;
			l[top++] = {i,1,a[i][1]-mn} ;
			l[top++] = {i,2,a[i][2]-mn} ;
		}
		if ( A == n )
		{
			int ret = 0 ;
			sort(AA,AA+n);
			for ( int i = n-1 ; i >= n/2 ; i -- )
			{
				ret += AA[i] ;
			}
			cout << ret << endl ;
		}
		else
		{
			if ( n <= 15 )
			{
				cout << dfs(0,0,0,0,0) << endl ;
			}
			else
			{
				sort(l,l+top,cmp); 
				int count[3] ;
				memset(count,0,sizeof(count));
				for ( int i = 0 ; i < top ; i ++ )
				{
					if ( ans[l[i].i] != -1 ) continue ;
					if ( count[l[i].p] == n/2 ) continue ;
					ans[l[i].i] = l[i].p ;
					count[l[i].p] ++ ;
				}
				int ret = 0 ;
				for ( int i = 0 ; i < n ; i ++ )
				{
					ret += a[i][ans[i]] ;
				}
				cout << ret << endl ;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}
