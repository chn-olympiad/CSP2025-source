#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5005,mod=998244353,inf=0x3f3f3f3f;
int n,f[MAXN][4],g[MAXN][4],a[MAXN];
inline int mmod(int x){
	return x%mod;
}
inline void gmod(int &x){
	x=mmod(x);
}
int ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5001;j++)
			f[j][0]=f[j][1]=f[j][2]=f[j][3]=0;
		f[a[i]][0]=1;
		for(int j=1;j<=5001;j++){
			gmod(f[min(5001ll,j+a[i])][1]+=g[j][0]);
			gmod(f[min(5001ll,j+a[i])][2+(a[i]<j)]+=mmod(g[j][1]+g[j][2]+g[j][3]));
		}
		for(int j=1;j<=5001;j++){
			gmod(g[j][0]+=f[j][0]);
			gmod(g[j][1]+=f[j][1]);
			gmod(g[j][2]+=f[j][2]);
			gmod(g[j][3]+=f[j][3]);
		}
	}
	for(int i=1;i<=5001;i++)
		gmod(ans+=g[i][3]);
	cout<<ans;
	return 0;
}

