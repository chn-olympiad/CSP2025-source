#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans = 0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for( int i = 1;i <= n;i++ ){
    	cin >> a[i];
	}
	int c = 0;
	for( int i = 1;i <= n;i++ ){
		c ^= a[i];
		if( c == k ){
			ans++;
			c = 0;
		}
	}
	cout << ans;
    return 0;
}
