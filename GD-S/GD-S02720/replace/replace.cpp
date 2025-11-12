#include <bits/stdc++.h>
#define LL long long
#define pr pair<int,int> 
#define add(u,v,w) g[u].push_back({v,w})
using namespace std ;
// T2
const int N=1e5+500 ;
int n,q ;
map <pair<string,string>,int> s ; 
int main () {
	freopen ("replace.in","r",stdin) ;
	freopen ("replace.out","w",stdout) ;
//	freopen ("hhh","w",stdout) ;
	cin>>n>>q ;
	for (int i=1;i<=n;i++) {
		string a,b ;
		cin>>a>>b ;
		s[{a,b}]++ ;
	}
	while (q--) {
		int ans=0 ;
		string a,b ; 
		cin>>a>>b ;
		int L=a.size() ;
		if (s.find ({a,b})!=s.end()) ans=1;
		for (int i=0;i<L;i++) {
			bool tc=0 ;
			for (int j=L-i-1;j>=1;j--) {
				string x,y,l,r ;
				x=a.substr (i,j); y=b.substr (i,j) ;
				l=a.substr (0,i),r=b.substr (0,i) ;
				if (l==r) {
					l=a.substr (i+j,L-i-j),r=b.substr (i+j,L-i-j) ;
					if (l==r && s.find({x,y})!=s.end()) ans+=s[{x,y}] ;
					else if (l!=r) break ;
//					cout<<i<<" "<<j<<"\n" ;
				} 
				else {
					tc=1 ; break ;
				}
			}
			if (tc) break ;
		}
		cout<<ans<<"\n" ;
	}
	return 0 ; 
}
