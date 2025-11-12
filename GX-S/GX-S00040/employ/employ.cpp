#include<iostream>
#include<algorithm>
#include<queue>
#include<array>
#include<bitset>
auto III=freopen("employ.in","r",stdin);
auto OOO=freopen("employ.out","w",stdout);
#define LL long long
#define pb push_back
#define vec vector
#define arr array
#define ALL(x) begin(x), end(x)
#define SIZ(x) signed((x).size())
#define RNG(x,l,r) &(x)[l], 1 + &(x)[r]
#define rep(i,l,r) for(int i=l, i##_=r; i<=i##_; i++)
#define per(i,l,r) for(int i=l, i##_=r; i>=i##_; i--)
void tomax(auto& x,auto&& y){if(y>x)x=y;}
void tomin(auto& x,auto&& y){if(y<x)x=y;}
using namespace std; namespace __{

constexpr int N=18+5, P=998244353;
void pl(auto& x,auto&& y){ x=(x+y)%P; }
int n,m;
string a;
int c[N];
int f[1<<19][N];

void main(){
	cin.tie(0)->sync_with_stdio(0);
	// signed cse; for(cin>>cse; cse--; clear())
[&](){
	cin>>n>>m>>a, a='`'+a+'`';
	rep(i,1,n) cin>>c[i];

	f[0][0]=1;
	rep(s,0,(1<<n)-1){
		rep(j,0,n){
			rep(k,1,n) if(s>>(k-1)&1^1){
				int t=s^(1<<(k-1));
				int i=__builtin_popcount(t);
				if(a[i]=='0' || j>=c[k]){
					pl(f[t][j+1], f[s][j]);
				}else{
					pl(f[t][j], f[s][j]);
				}
			}
		}
		// cout<<bitset<3>(s)<<' ';
		// rep(j,0,n) cout<<f[s][j]<<' ';
		// cout<<endl;
	}
	int ans=0;
	rep(j,0,n-m){
		pl(ans,f[(1<<n)-1][j]);
	}
	cout<<ans;
}();}}
signed main(){__::main();return 0;}
