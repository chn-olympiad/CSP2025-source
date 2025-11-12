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
	const int N=(int)(205),P=(int)(998244353);
	const int inf=(int)(1e9);
	int A[N][3],f[N][N][N],len[3];
	int n;
	bool flag=true;
	void SOLVE(){
		cin>>n;up(i,1,n)cin>>A[i][0]>>A[i][1]>>A[i][2],flag&=(A[i][1]==0&&A[i][2]==0);
		if(n<=200){
			up(i,1,n)up(a,0,Min(i,n/2))up(b,0,Min(i,n/2)){
				f[i][a][b]=f[i-1][a][b];
				if(a>0)f[i][a][b]=Max(f[i-1][a-1][b]+A[i][0],f[i][a][b]);
				if(b>0)f[i][a][b]=Max(f[i-1][a][b-1]+A[i][1],f[i][a][b]);
				if(i-a-b>0&&i-a-b<=Min(i,n/2))f[i][a][b]=Max(f[i-1][a][b]+A[i][2],f[i][a][b]);
			}
			int ans=0;
			up(i,0,n/2)up(j,0,n/2)ans=Max(ans,f[n][i][j]);
			cout<<ans<<'\n';
			return ;
		}
		if(flag){
			vi k;up(i,1,n)k.push_back(A[i][0]);
			sort(k.begin(),k.end(),greater<int>());
			int ans=0;
			up(i,0,n/2-1)ans+=k[i];
			cout<<ans<<'\n';
			return ;
		}
		len[0]=len[1]=len[2]=0;
		int ans=0;
		up(i,1,n){
			vpi c;
			c.push_back({A[i][0],0});
			c.push_back({A[i][1],1});
			c.push_back({A[i][2],2});
			sort(c.begin(),c.end(),[&](pii x,pii y){
				return x.fst>y.fst;
			});
			int c0=c[0].sed;
			int c1=c[1].sed;
			int c2=c[2].sed;
			if(len[c0]<=n/2)ans+=c[0].fst;
			else if(len[c1]<=n/2)ans+=c[1].fst;
			else if(len[c2]<=n/2)ans+=c[2].fst;
		}cout<<ans<<'\n';
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int _=1;cin>>_;while(_--)my::SOLVE();return 0;
}
/*
 f[i][a][b][c]=
 	if(a>0)chkmax(f[i-1][a-1][b][c]+a[i][0])
 	if(b>0)chkmax(f[i-1][a][b-1][c]+a[i][1])
 	if(c>0)chkmax(f[i-1][a][b][c-1]+a[i][2])
c=i-a-b

is O(n^3) how to solve this problem I just thought this dp but it's very slow

*/
