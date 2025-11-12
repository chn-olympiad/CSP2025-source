#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int a[5005];
int b[5005];
int ans;
bool ck(int x){
	int ma=0,sum=0;
	for( int i = 1 ; i <= x ; i++ ){
		sum += b[i];
		ma = max(b[i],ma);
	}
	return sum > ( ma * 2 );
}
void pl(int sstep,int step,int now){
	if( step != 0 ){
		for( int i = now ; i <= n - step + 1 ; i++ ){
 			pl(sstep,step-1,i+1);
		}
	} else {
		if( ck(sstep) ){
			ans++;
		}
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if( n < 3 ){
		cout << 0;
		return 0;
	}
	if( n == 3 ){
		if( a[1] + a[2] + a[3] > 2 * max(a[1],max(a[2],a[3])) ){
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	for( int i = 3 ; i <= n ; i++ ){
		pl(i,i,1);
	}
	cout << ans;
	return 0;
} 

