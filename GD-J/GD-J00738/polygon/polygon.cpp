#include<bits/stdc++.h>
using namespace std;
const long long N = 5005,mod = 998244353;
long long n,a[N],c[N][N],ans = 0;
bool ok = true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if( a[i] > 1) ok = false;
	}
	if( ok ){
		for(int i = 1;i <= n;i++) {
			c[i][i] = 1;
			c[i][1] = i;
			c[i][0] = 1;
		}
		for(int i = 2;i <= n;i++)
			for(int j = 2;j < i;j++)
				c[i][j] = ( c[i-1][j] + c[i-1][j-1] )%mod;
		for(int i = 3;i <= n;i++) ans = (ans + c[n][i])%mod;
		cout << ans <<"\n";
	}else{
		long long sum = 0,maxx = 0,cnt = 0;
		for(int i = 1;i < (1 << n);i++){
			sum = maxx = cnt = 0;
			for(int j = 1;j <= n;j++){
				if( i&(1 << (j-1) ) ){
					sum += a[j];
					maxx = max( maxx, a[j] );
					++cnt;
				}
			}
			if( cnt > 2 && sum > maxx*2 ) ++ans;
		}
		cout << ans <<"\n";
	}
	return 0;
}

