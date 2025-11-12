#include<iostream>
#define int long long
#define endl "\n"
using namespace std;
const int N=505,M=5e5+5,mod=998244353;
int f[M][20];
int a[N],c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	f[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++){
		int now=1;
		for(int j=1;j<=n;j++)if(i>>(j-1)&1)now++;
		for(int j=1;j<=n;j++){
			if(i>>(j-1)&1)continue;
			for(int k=0;k<=n;k++){
				if(!f[i][k])continue;
				if(c[j]<=k || !a[now])f[i^(1<<j-1)][k+1]=(f[i^(1<<j-1)][k+1]+f[i][k])%mod;
				else f[i^(1<<j-1)][k]=(f[i^(1<<j-1)][k]+f[i][k])%mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)ans=(ans+f[(1<<n)-1][i])%mod;
	cout<<ans<<endl;
}
