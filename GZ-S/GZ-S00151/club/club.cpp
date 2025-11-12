//GZ-S00151 贵阳市云岩区中天中学 张善之 
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5+20 ;
struct plea {
	int a,b,c,he;
	bool a11,b11,c11 ;
}m[N];
bool cmp1(plea q,plea p) {
	if(q.a>p.a) return true ;
	else return false ;
}
bool cmp2(plea q,plea p) {
	if(q.b>p.b) return true ;
	else return false ;
}
bool cmp3(plea q,plea p) {
	if(q.c>p.c) return true ;
	else return false ;
}
bool cmp4(plea q,plea p) {
	if(q.he>q.he) return true ;
	else return false ;
}
int cnt[3] ;
int main () {
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	int T ; cin >> T ;
	for(int a=1;a<=T;a++) {
		int n = 0 ; cin >> n ;
		for(int i=1;i<=n;i++){
			cin >> m[i].a >> m[i].b >> m[i].c ;
			m[i].a11=false ; m[i].b11=false ; m[i].c11=false ; 
			m[i].he=0 ; m[i].he=m[i].a + m[i].b + m[i].c ;
		}
		int hal = n/2 ;
		sort(m+1,m+n+1,cmp1) ;
		for(int i=1;i<=hal;i++) {
			m[i].a11 = true ; 
		}
		sort(m+1,m+n+1,cmp2) ;
		for(int i=1;i<=hal;i++) {
			m[i].b11 = true ; 
		}
		sort(m+1,m+n+1,cmp3) ;
		for(int i=1;i<=hal;i++) {
			m[i].c11 = true ; 
		}
		sort(m+1,m+n+1,cmp4) ;
		int ans1=0;
		for(int i=1;i<=n;i++){
			int ma = 0 ;
			if(m[i].a11==true){ma = max(ma,m[i].a) ; } 
			if(m[i].b11==true){ma = max(ma,m[i].b) ; } 
			if(m[i].c11==true){ma = max(ma,m[i].c) ; } 
			ans1+=ma ; 
		}
		cout << ans1 <<"\n";
	} 
	return 0 ;
}


