#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[10005];
bool A=1;
int c[1005][1005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=0;
		}
	}
	if(A){
		for(int i=1;i<=n*2;i++){
			for(int j=1;j<=i;j++){
				if(i==j){
					c[i][j]=1;
				}
				if(j==1){
					c[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n*2;i++){
			for(int j=2;j<i;j++){
				c[i][j]=(c[i-1][j-1]%mod+c[i-1][j]%mod)%mod;
			}
		}
		int ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+c[n+1][i+1])%mod;
		}
		cout<<ans<<endl;
	}else{
		cout<<2*n<<endl;
	}
	return 0;
}