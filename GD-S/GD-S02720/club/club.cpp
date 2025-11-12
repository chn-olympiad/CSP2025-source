#include <bits/stdc++.h>
#define LL long long 
using namespace std ;
// T1
const int N=1e5+500 ; 
int T,n,a[N][5],f[N],ans,s[5] ;
bool cmp (int a,int b) {
	return a>b ;
}
vector <int> v ;
void sol () {
	scanf ("%d",&n) ;
	ans=0 ;
	s[1]=s[2]=s[3]=0 ;
	v.clear() ;
	for (int i=1;i<=n;i++) {
		int ma=0; 
		for (int j=1;j<=3;j++) {
			scanf ("%d",&a[i][j]) ;
			if (a[i][j]>=a[i][ma]) ma=j ;
		}
		f[i]=ma ;
		ans+=a[i][ma] ;
		++s[ma] ;
	}
	int x,y ;
	for (int i=1;i<=3;i++) {
		if (s[i]>n/2) {
			if (i==1) x=2,y=3 ;
			if (i==2) x=1,y=3 ;
			if (i==3) x=1,y=2 ; 
			for (int j=1;j<=n;j++) {
				if (f[j]==i) {
					v.push_back(min (a[j][f[j]]-a[j][x],a[j][f[j]]-a[j][y])) ;
				}
			}
			sort (v.begin(),v.end(),cmp) ;
			while (v.size()) {
				s[i]-- ;
				ans-=v.back() ; v.pop_back () ;
				if (s[i]<=n/2) break ;
			}
			break ;
		}
	}
	printf ("%d\n",ans) ;
}
int main () {
	freopen ("club.in","r",stdin) ;
	freopen ("club.out","w",stdout) ;
//	freopen ("hh","w",stdout) ;
	
	cin>>T ;
	while (T--) {
		sol () ;
	}
	return 0 ; 
}
