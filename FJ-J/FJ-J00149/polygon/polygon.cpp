#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,a[5010],f[5010][5005],c[5015],p[5015],mod=998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	p[0]=1;
	for(int i=1;i<=n;i++){
		c[i]=(c[i-1]+a[i])%mod;
		p[i]=(p[i-1]*2)%mod;
	}
	f[1][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5025;j++){
			if(j<a[i]) f[i][j] = (f[i-1][j]+p[i-1]) % mod;
			else f[i][j] = max( f[i][j] , (f[i-1][j-a[i]]+f[i-1][j])%mod );
			//cout << f[i][j]<<' ';
		}
		//cout << '\n';
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		ans=(ans+f[i-1][a[i]])%mod;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
