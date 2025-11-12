#include<bits/stdc++.h>
using namespace std ;
int n , m , k ;
const int M = 1e7 + 10 , N = 1e4 + 10 ;
int f[N] ;
long long a[N] ;
struct node
{
	int u ;
	int v ;
	long long w ;
} e[M] ;
bool cmp(node x , node y)
{
	return x.w < y.w ;
}
int find(int x)
{
	if(x == f[x]) return x ;
	return (f[x] = find(f[x])) ;
}
int main()
{
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	scanf("%d%d%d",&n,&m,&k) ;
	for(int i = 1 ; i <= n ; i++)
		f[i] = i ;
	for(int i = 1 ; i <= m ; i++)
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w) ;
	long long t = 0 ;
	for(int i = 1 ; i <= k ; i++)
	{
		long long x ;
		scanf("%lld",&x) ;
		for(int j = 1 ; j <= n ; j++)
		{
			scanf("%lld",&a[j]) ;
			for(int l = 1 ; l < j ; l++)
				e[++m] = {l,j,x + a[l] + a[j]} ;
		}
	}
	sort(e + 1,e + 1 + m,cmp) ;
	for(int i = 1 , j = 0 ; j < n && i <= m ; i++)
	{
		int u = e[i].u , v = e[i].v ;
		long long w = e[i].w ;
		int s = find(u) , p = find(v) ;
		if(s == p) continue ;
		f[s] = p ;
		t += w ;
		j++ ;
	}
	printf("%lld",t) ;
	return 0 ;
}
