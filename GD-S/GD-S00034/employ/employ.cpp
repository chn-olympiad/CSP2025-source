#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define mod 998244353
#define endl '\n'
using namespace std;
constexpr int N=510;
int n,m;
char s[N];
int c[N],jc[N];
int qsm(int x,int k){
	int res=1;
	while(k){
		if(k&1)res=1LL*res*x%mod;
		k>>=1,x=1LL*x*x%mod;
	}
	return res;
}
namespace stk1{
	bool st[15];
	int p[N],ans;
	void check(){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=c[p[i]])cnt++;
		}
		if((n-cnt)>=m)ans++;
	}
	void dfs(int x){
		if(x==n+1)return check();
		for(int i=1;i<=n;i++){
			if(!st[i]){
				st[i]=1;
				p[x]=i;
				dfs(x+1);
				st[i]=0;
			}
		}
	}
	void solve(){
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
}
namespace stk2{
	int f[20][1<<19][20];
	void solve(){
		int U=(1<<n)-1;
		f[0][0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=U;j++){
				for(int k=0;k<n;k++){
					if(j>>k&1^1){
						for(int jj=0;jj<n;jj++){
							if(s[i]=='0'||jj>=c[k+1])
								f[i][j|(1<<k)][jj+1]+=f[i-1][j][jj];
							else f[i][j|(1<<k)][jj]+=f[i-1][j][jj];
							if(f[i][j|(1<<k)][jj+1]>=mod)f[i][j|(1<<k)][jj+1]-=mod;
							if(f[i][j|(1<<k)][jj]>=mod)f[i][j|(1<<k)][jj]-=mod;
						}
					}
				}
			}
		}
		ll ans=0;
		for(int i=0;i<=n-m;i++)ans+=f[n][U][i];
		cout<<ans%mod;
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	jc[0]=1;
	for(int i=1;i<=500;i++)jc[i]=jc[i-1]*1LL*i%mod;
	cin>>s+1;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		bool hf=1;
		for(int i=1;i<=n;i++)if(s[i]=='0')hf=0;
		for(int i=1;i<=n;i++)if(c[i]==0)hf=0;
		if(hf)cout<<jc[n]<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(n<=18)return stk2::solve(),0;




	return 0;
}

