#include<bits/stdc++.h>
using namespace std ;
const int N=5e5+10 ;
#define ll long long
ll a[N] , s[N] , n , k ;
struct point {
	ll start , end ;
	point( ll start , ll end ) : start(start) , end(end) {}
	bool operator < ( const point b ) const {
		return end<b.end ;
	}
};
vector<point> x ;
int main() {
	freopen("xor.in","r",stdin) ;
	freopen("xor.out","w",stdout) ;
	cin>> n >> k ;
	for ( int i=1 ; i<=n ; i++ ) {
		cin>> a[i] ;
		s[i]=s[i-1]^a[i] ; 
	}
//	for ( int i=1 ; i<=n ; i++ ) {
//		cout<< s[i] << " " ;
//	}
	for ( int i=1 ; i<=n ; i++ ) {
		for ( int j=i ; j<=n ; j++ ) {
			if ( (s[j]^s[i-1])==k ) {
				x.push_back(point(i,j)) ;
				break ;
			}
		}
	}
	sort(x.begin(),x.end()) ;
//	for ( int i=0 ; i<x.size() ; i++ ) {
//		cout<< x[i].start << " " << x[i].end << endl ;
//	}
	ll ans=1 , choose=0 ;
	for ( int i=1 ; i<x.size() ; i++ ) {
		if ( x[i].start>x[choose].end ) {
			ans++ ;
			choose=i ;
		}
	}
	cout<< ans ;
	return 0 ;
}

