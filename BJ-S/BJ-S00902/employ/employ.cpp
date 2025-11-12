#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int p=998244353;
int n,m,f1[2][510],c[510],c1[510];
ll qp(ll a,ll b,ll ans=1){for(a%=p;b;a=a*a%p,b>>=1)if(b&1)ans=ans*a%p;return ans;}
void M(int&x){x>=p&&(x-=p);}
string s;
int main(){
	fre("employ"),cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1,t;i<=n;++i)cin>>t,++c[t];c1[0]=c[0];
	for(int i=1;i<=n;++i)c1[i]=c1[i-1]+c[i];
	int res=0;
	ll ans=0;
	ll tmp=1;
	for(int i=1;i<=n;++i)tmp=tmp*i%p;
	for(int TT=0;TT<m;++TT){
		res=0;
		memset(f1,0,sizeof(f1));
		f1[0][0]=1;
		for(int i=1;i<=n;++i){
			const int u=i&1,v=!u;memset(f1[u],0,sizeof(f1[u]));
			if(s[i-1]&1){//1 case
				//boom
				for(int j=res;j<i;++j)if(c1[j]>j-res){
					M(f1[u][j+1]+=1ll*f1[v][j]*(c1[j]-(j-res))%p);
					// cerr<<u<<' '<<j+1<<' '<<f[u][j+1]<<'\n';
				}
				//not boom
				for(int j=0;j<i;++j)if(n-c1[j]>TT-(i-j)){
					// cerr<<i<<' '<<TT<<' '<<j<<' '<<n-c1[j]-(TT-(i-j))<<' '<<f1[v][j]<<'\n';
					M(f1[u][j]+=1ll*f1[v][j]*(n-c1[j]-(TT-(i-j)))%p);
				}
			}else{//0 case
				++res,memcpy(f1[u]+1,f1[v],sizeof(int)*500);
			}
		}
		// cerr<<TT<<' '<<f1[n&1][n-TT]<<'\n';
		ans=(ans+f1[n&1][n-TT])%p;
	}
	for(int i=1;i<=res;++i)ans=ans*i%p;
	cout<<(tmp-ans+p)%p<<'\n';
	return 0;
}