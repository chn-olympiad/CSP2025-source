#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define dF(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ll long long
#define uint unsigned
#define ull unsigned long long
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define lowbit(x) ((x)&(-(x)))
using namespace std;
bool ST;
template<typename T>inline void chkmax(T &x,const T y){ x=max(x,y); }
template<typename T>inline void chkmin(T &x,const T y){ x=min(x,y); }
const int inf=1000000005;
const ll infll=1000000000000000005ll;
const int maxn=505,mod=998244353;
inline void inc(int&x,int y){ x=(x+y>=mod)?(x+y-mod):(x+y); }
inline void dec(int&x,int y){ x=(x>=y)?x-y:(x-y+mod); }
inline int add(int x,int y){ return (x+y>=mod)?(x+y-mod):(x+y); }
inline int sub(int x,int y){ return (x>=y)?x-y:(x-y+mod); }
void fre(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
}
int n,m,col[maxn],a[maxn],occ[maxn],pre[maxn];
int C[maxn][maxn],fac[maxn];
string str;
int f[maxn][maxn],g[maxn][maxn];
void Solve_(){
	cin>>n>>m>>str,str=' '+str;
	fac[0]=1;
	F(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	F(i,0,n)C[i][0]=1;
	F(i,1,n)F(j,1,i)C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	F(i,1,n)col[i]=(str[i]=='1');
	F(i,1,n)cin>>a[i],++occ[a[i]];
	F(i,0,n)pre[i]=(i==0?0:pre[i-1])+occ[i];
	f[0][0]=1;
	F(i,1,n){
		memset(g,0,sizeof g);
		if(col[i]==0){
			// j -> j+1
			F(j,0,i)F(k,0,i){
				const int val=f[j][k];if(!val)continue;
				F(l,0,min(k,occ[j+1])){
					const int tmp=1ll*val*C[occ[j+1]][l]%mod*C[k][l]%mod*fac[l]%mod;
					if(tmp){
						inc(g[j+1][k-l+1],tmp);
						if(pre[j]>i-1-k)inc(g[j+1][k-l],1ll*tmp*(pre[j]-(i-1-k))%mod);
					}
					inc(g[j+1][k-l],1ll*val*C[occ[j+1]][l+1]%mod*C[k][l]%mod*fac[l+1]%mod);
				}
			}
		} else{
			F(j,0,i)F(k,0,i){
				const int val=f[j][k];if(!val)continue;
				inc(g[j][k+1],val);
				if(pre[j]>i-1-k){
					F(l,0,min(occ[j+1],k))inc(g[j+1][k-l],1ll*val*C[occ[j+1]][l]%mod*(pre[j]-(i-1-k))%mod*C[k][l]%mod*fac[l]%mod);
				}
			}
		}
		memcpy(f,g,sizeof g);
	}
	int ans=0;
	F(i,0,n-m)F(j,0,n){
		const int val=f[i][j];if(!val)continue;
		if(j>pre[n]-pre[i])continue;
		inc(ans,1ll*val*fac[j]%mod);
	}
	cout<<ans<<'\n';
}
bool ED;
signed main(){
	fre(),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int zsy=1;// cin>>zsy;
	F(_,1,zsy)Solve_();
}
// g++ test.cpp -o a -std=c++14 -O2