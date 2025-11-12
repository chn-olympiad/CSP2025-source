#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define mset multiset
#define pq priority_queue
#define ull unsigned long long
#define i128 __int128
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
const int maxn=500+10;
const int mod=998244353;
int n,m,a[maxn];
string s;
void add(int &x,int y){
	x=(x+y)%mod;
}
namespace Solve1{
	const int maxs=(1<<18)+10;
	int f[maxs][maxn],p[maxs];
	void solve(){
		for(int i=1;i<(1<<18);i++) p[i]=p[i>>1]+(i&1);
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1) continue;
				for(int k=0;k<=n;k++){
					if(s[p[i]+1]=='0'||a[j]<=k) add(f[i+(1<<(j-1))][k+1],f[i][k]);
					else add(f[i+(1<<(j-1))][k],f[i][k]);
				}
			}
		}
		int res=0;
		for(int i=0;i<=n-m;i++) add(res,f[(1<<n)-1][i]);
		cout<<res<<endl;
	}
}
namespace Solve2{
	void solve(){
		for(int i=1;i<=n;i++) if(s[i]=='0') return cout<<0<<endl,void();
		for(int i=1;i<=n;i++) if(a[i]==0) return cout<<0<<endl,void();
		int res=1;
		for(int i=1;i<=n;i++) res=1ll*res*i%mod;
		cout<<res<<endl;
	}
}
namespace Solve3{
	int f[maxn][maxn],c[maxn],sum[maxn];
	void solve(){
		f[0][0]=1;
		for(int i=1;i<=n;i++) c[a[i]]++;
		for(int i=n;~i;i--) sum[i]=sum[i+1]+c[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++) if(c[i]) add(f[i+1][j+c[i]-1],1ll*f[i][j]*c[i]%mod);
			for(int j=1;j<=n;j++) add(f[i+1][j+c[i]-1],1ll*f[i][j]*j%mod);
			if(s[i+1]=='0'){
				for(int j=0;j<=n;j++) add(f[i+1][j+c[i]],1ll*f[i][j]*sum[i+1]%mod);
			}
		}
		int all=1;
		for(int i=1;i<=n;i++) all=1ll*all*i%mod;
		cout<<(all-f[n][0]+mod)%mod<<endl;
	}
}
void solve(){
	cin>>n>>m>>s,s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
//	Solve3::solve();
	if(n<=18) Solve1::solve();
	else if(n==m) Solve2::solve();
	else if(m==1) Solve3::solve();
}
int main(){
	FileIO("employ");
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}
/*
5 1
01011
0 0 1 1 2
*/
