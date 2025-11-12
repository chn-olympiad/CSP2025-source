#include <bits/stdc++.h>

using namespace std ;
#define ll long long

const int N = 110 ;

int n , m ;

struct node{
	int v , id ;
}a[N * N];

bool cmp (node d , node e) {
	return d.v > e.v ;
}

int main () {
   freopen ("seat.in" , "r" , stdin) ;
   freopen ("seat.out" , "w" , stdout) ;
  
  cin >> n >> m ;
  
  for (int i = 1 ; i <= n * m ; ++i) {
  	cin >> a[i].v ; 
  	a[i].id = i ;
  }
	
	sort (a + 1 , a + 1 + n * m , cmp) ;
	
	int l = 1 , h = 0 ;
	
	int t = 1 ;
	
	bool ok = 0 ;
	for (int i = 1 ; i <= n * m;  ++i) {
		if (!ok)	h += t ;
		else ok = 0 ;
		if (a[i].id == 1) {
			printf ("%d %d" , l , h) ;
			return 0 ;
		}
		if (h == n && t == 1) {
			ok = 1 ;
			t = -t ;
			++l ;
		}
		else if (t == -1 && h == 1) {
			t = -t ;
			ok = 1 ;
			++l ;
		}
	}

  return 0 ;
}
