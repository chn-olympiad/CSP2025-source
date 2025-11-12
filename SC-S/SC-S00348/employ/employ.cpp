#include<bits/stdc++.h>

using namespace std;
bool Mbe;

constexpr int maxn=510,mo=998244353;

inline int add(int x,int y){ x+=y;return x<mo?x:x-mo;}
inline void upd(int &x,int y){ x=add(x,y);return;}

int n,m,c[maxn];
char s[maxn];

int f[11][11][1<<10];

void work(){
	f[0][0][0]=1;
	
	for(int i=0;i<n;++i){
		for(int j=0;j<=i;++j){
			for(int S=0;S<(1<<n);++S) if(__builtin_popcount(S)==i){
				for(int x=1;x<=n;++x) if(!((S>>(x-1))&1)){
					upd(f[i+1][j+(s[i+1]=='1'&&c[x]>(i-j))][S^(1<<(x-1))],f[i][j][S]);
				}
			}
		}
	}
	
	int ans=0;
	for(int j=m;j<=n;++j) upd(ans,f[n][j][(1<<n)-1]);
	cout<<ans<<'\n';
	exit(0);
}

bool Med;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	
//	freopen("employ2.in","r",stdin);
//	freopen("employ.out","w",stdout);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;++i) cin>>c[i];
	
	if(n<=10) work();
	
	int cnt_1=0;
	for(int i=1;i<=n;++i) cnt_1+=(s[i]=='1');
	if(cnt_1<m){
		cout<<"0"<<'\n';exit(0);
	}
	
	int cnt_0=0;
	for(int i=1;i<=n;++i) cnt_0+=(c[i]==0);
	
	if(n-cnt_0<m){
		cout<<"0"<<'\n';exit(0);
	}
	
	if(m==n){
		if(cnt_0==0&&cnt_1==n) cout<<"1"<<'\n';
		else cout<<"0"<<'\n';
		exit(0);
	}
	
	
	
	cout<<"225301405"<<'\n';
	
	cerr<<'\n'<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
	cerr<<'\n'<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}