#include <bits/stdc++.h>
#define up(a,b,c) for(int (a)=(b);(a)<=(c);(a)++)
#define dn(a,b,c) for(int (a)=(b);(a)>=(c);(a)--)
#define fst first
#define sed second
#define Max(x,y) (((x)>(y))?(x):(y))
#define Min(x,y) (((x)<(y))?(x):(y))
#define Abs(x) (((x)<0)?(-(x)):(x))
using namespace std;
using ll=long long;using ull=unsigned long long;using hint=__int128;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pil=pair<int,ll>;
using pli=pair<ll,int>;using vi=vector<int>;using vl=vector<ll>;
using vpi=vector<pii>;using vpl=vector<pll>;using vpli=vector<pli>;
using vpil=vector<pil>;using ui=unsigned int;using db=double;
using ldb=long double;
namespace my{
	const int N=(int)(505),P=(int)(998244353);
	const int inf=(int)(1e9);
	int n,m,ans=0;
	string s;
	int c[N],p[N];
	bool vis[N];
	void dfs(int x){
		if(x>n){
			int out=0,in=0;
//			up(i,1,n)cout<<p[i]<<' ';cout<<'\n';
			up(i,1,n){
//				cout<<out<<' '<<in<<'\n';
				if(s[i]=='0'){
					out++;
					continue;
				}
				if(out>=c[p[i]]){
					out++;
					continue;
				}
				if(s[i]=='1'){
					in++;
					continue;
				}
			}
//			cout<<in<<'\n';
			if(in>=m){
//				up(i,1,n)cout<<p[i]<<' ';cout<<'\n';
				ans++;
			}
			return ;
		}
		up(i,1,n){
			if(vis[i])continue;
			p[x]=i;vis[i]=true;
			dfs(x+1);
			p[x]=0;vis[i]=false;
		}
	}
	void SOLVE(){
		cin>>n>>m;cin>>s;s=" "+s;
		up(i,1,n)cin>>c[i];
		dfs(1);cout<<ans%P<<'\n';
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int _=1;while(_--)my::SOLVE();return 0;
}
/*
I will got [208,268]pts
*/
