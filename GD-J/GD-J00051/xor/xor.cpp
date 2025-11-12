#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 10 ;
map<int,int> b ;
int s[N] ;
int d[N] ;
int a[N] ;
int f[N] ;
int main()
{
	freopen("xor.in","r",stdin) ;
	freopen("xor.out","w",stdout) ;
	int n , k ;
	scanf("%d%d",&n,&k) ;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]) ;
		s[i] = s[i - 1] ^ a[i] ;
		if(a[i] == k) d[i] = i ;
		else if(b[s[i] ^ k]) d[i] = b[s[i] ^ k] + 1 ;
		b[s[i]] = i ;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(d[i] == 0) f[i] = f[i - 1] ;
		else f[i] = max(f[i - 1],f[d[i] - 1] + 1) ;
	}
	printf("%d",f[n]) ;
	return 0 ;
}
