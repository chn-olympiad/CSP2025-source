#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N=5005,M=998244353;
typedef long long ll;
int n,a[N],vis[N];
ll ans,f[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<=a[1];++i) f[1][i]=1;
	for(int i=2;i<=n;++i){
		for(int j=a[i-1],w=i-1;j<a[i];++j) vis[j]=w;
		int nu=a[i];
		for(int j=1;j<=a[i];++j) f[i][j]=((f[i-1][j]<<1|1)%M+vis[j-1])%M;
		while(1){
			++nu;
			f[i][nu]=((f[i-1][nu]<<1)%M+f[i-1][nu-a[i]])%M;
			if(!f[i][nu]) break;
		}
	}
	for(int i=2;i<n;++i) for(int j=i+1;j<=n;++j) ans+=f[i-1][a[j]+1-a[i]]%M;
	cout<<ans;
	return 0;
} 
