#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
const int N=5010,M=10001;
int n,a[N],f[N][N*2][2],ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=M;j++){
			f[i][j][0]=(f[i][j][0]+(f[i-1][j][0]+f[i-1][j][1])%mod)%mod;
			f[i][min(M,j+a[i])][1]=(f[i][min(M,j+a[i])][1]+(f[i-1][j][0]+f[i-1][j][1])%mod)%mod;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=a[i]*2+1;j<=M;j++) ans=(ans+f[i][j][1])%mod;
	}
	cout<<ans;
	return 0;
}

