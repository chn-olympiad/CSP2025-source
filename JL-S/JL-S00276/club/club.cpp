#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int t, n, site, ans, lose;
int s[4];
int a[100003][4], b[100003][4];
priority_queue< int , vector<int>, greater<int> >Q;
//pair<int,int>d;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while( t-- ){
		cin >> n;
		ans =0;  lose =0;
		while( Q.size()!=0 )  Q.pop();
		for(int i=1; i<=3; i++)  s[i] =0;
		//cout << Q.size() << endl;
		for(int i=1; i<=n; i++){
			int maxin =0;
			for(int j=1; j<=3; j++){
				b[i][j] =0;
				cin >> a[i][j];
				if( a[i][j]>maxin ){
					maxin =a[i][j];
					site =j;
				}
			}
			b[i][site] =1;
			s[site] ++;
			ans +=maxin;
		}
		if( s[1] >(n/2) ){
			int q =s[1] -(n/2);
			for(int i=1; i<=n; i++){
				if( b[i][1] ==1 ){
					lose =a[i][1] -max( a[i][2], a[i][3] );
					Q.push( lose );
				}
			}
			while( q-- ){
				ans -=Q.top();
				Q.pop();
				//ans -=d.fi;
				//lose =d.fi-max( a[d.se][2], a[d.se][3] );
				//O.push( { lose, d.se } );
				//ans +=max( a[d.se][2], a[d.se][3] );
			}
		}
		if( s[2] >(n/2) ){
			int q =s[2] -(n/2);
			for(int i=1; i<=n; i++){
				if( b[i][2] ==1 ){
					lose =a[i][2] -max( a[i][1], a[i][3] );
					Q.push( lose );
				}
			}
			while( q-- ){
				ans -=Q.top();
				Q.pop();
			}
		}
		if( s[3] >(n/2) ){
			int q =s[3] -(n/2);
			for(int i=1; i<=n; i++){
				if( b[i][3] ==1 ){
					lose =a[i][3] -max( a[i][2], a[i][1] );
					Q.push( lose );
				}
			}
			while( q-- ){
				ans -=Q.top();
				Q.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
