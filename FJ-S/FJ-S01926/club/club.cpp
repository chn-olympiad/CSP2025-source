#include<bits/stdc++.h>
using namespace std;
struct member{
	int x,y,z;
}a[100005];
bool cmp1(member a,member b){
	return a.x > b.x;
}
int ma = 0;
int T,n;
bool ta=1,tb=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while( T-- ){
		cin >> n;
		for( int i = 1 ; i <= n ; i++ ){
			cin >> a[i].x >> a[i].y >> a[i].z; 
			if( a[i].y != 0 || a[i].z != 0 ){
				ta = 0;
			}
			if( a[i].z != 0 ){
				tb = 0;
			}
		}
		int sum = 0;
		if( ta ){
			sort(a+1,a+n+1,cmp1);
			for( int i = 1 ; i <= n / 2 ; i++ ){
				sum += a[i].x;
			}
			cout << sum;
		} else if( n == 2 ){
			int max1 = max(max(a[1].x,a[1].y),a[1].z);
			int max2 = max(max(a[2].x,a[2].y),a[2].z);
			int zb1,zb2;
			if( max1 == a[1].x )zb1 = 1;
			if( max1 == a[1].y )zb1 = 2;
			if( max1 == a[1].z )zb1 = 3;
			if( max2 == a[2].x )zb2 = 1;
			if( max2 == a[2].y )zb2 = 2;
			if( max2 == a[2].z )zb2 = 3;
			if( zb1 != zb2 ){
				cout << max1 + max2;
			} else {
				int ma1,ma2;
				if( zb1 == 1 ) ma1 = max(a[1].y,a[1].z);
				if( zb1 == 2 ) ma1 = max(a[1].x,a[1].z);
				if( zb1 == 3 ) ma1 = max(a[1].y,a[1].x);
				if( zb2 == 1 ) ma2 = max(a[1].y,a[1].z);
				if( zb2 == 2 ) ma2 = max(a[1].x,a[1].z);
				if( zb2 == 3 ) ma2 = max(a[1].y,a[1].x);
				cout << max(ma2+max1,ma1+max2);
			}
		} else {
			for( int i = 1 ; i <= n ; i++ ){
				sum += max(a[i].x,max(a[i].y,a[i].z));
			}
			cout << sum;
		}
	}
	return 0;
}       
