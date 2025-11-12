#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int n,a[5010],f[10010][2],tmp[10010][2],g[10010][2],tmp2[10010][2];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	f[0][0]=1;g[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=10000;j>=0;j--){
			tmp[j][0]=tmp[j][1]=0;
			tmp2[j][0]=tmp2[j][1]=0;
		}
		for(int j=10000;j>=0;j--){
			if(j+a[i]<=10000){
				if(j+a[i]<=2*a[i]){
					tmp[j+a[i]][1]=(tmp[j+a[i]][1]+(g[j][0]+g[j][1])%mod)%mod;
				}
				tmp2[j+a[i]][1]=(tmp2[j+a[i]][1]+(g[j][0]+g[j][1])%mod)%mod;
			}
			tmp[j][0]=(tmp[j][0]+(f[j][0]+f[j][1])%mod)%mod;
			tmp2[j][0]=(tmp2[j][0]+(g[j][0]+g[j][1])%mod)%mod;
		}
		for(int j=10000;j>=0;j--){
			f[j][0]=tmp[j][0];
			f[j][1]=tmp[j][1];
			g[j][0]=tmp2[j][0];
			g[j][1]=tmp2[j][1];
		}
	}
	int ans=0;
	for(int i=0;i<=10000;i++){
		ans=(ans+f[i][0])%mod;
		ans=(ans+f[i][1])%mod;
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		sum=(sum*2)%mod;
	}
	int res=(sum-ans+mod)%mod;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(max(a[i],a[j])*2<a[i]+a[j]){
				cnt++;
				res=(res-1+mod)%mod;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
