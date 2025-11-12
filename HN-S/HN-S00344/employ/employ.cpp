#include<bits/stdc++.h>
#define int long long 
const int mod=998244353; 
int gi(){
	char c;int x=0,f=0;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))x=(x*10)+(c^48),c=getchar();
	return f?-x:x;
}
std::mt19937 rnd(std::random_device{}());
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end() 
#define mem(x,w) memest(x,w,sizeof(x)) 
#define sz(x) (int)((x).size()) 
#define fi first
#define se second 
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
template<class T>void inc(T&a,T b){a=a+b>=mod?a+b-mod:a+b;}
template<class T>void dec(T&a,T b){a=a>=b?a-b:a+mod-b;}
char s[505];
int n,m,ans,c[505],a[505];
int f[20][20][262155],cnt0;
bool vis[15];
int p[15];
bool chkA(){for(int i=1;i<=n;i++)if(!a[i])return 0;return 1;}
int calc(){
	int lq=0;
	for(int i=1;i<=n;i++){
		if(i-1-lq>=c[p[i]])continue;
		lq+=a[i];
	}
	return lq>=m;
}
void dfs(int x){
	if(x==n+1)return ans+=calc(),void();
	for(int i=1;i<=n;i++)if(!vis[i])vis[i]=1,p[x]=i,dfs(x+1),vis[i]=0;
}
signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	n=gi(),m=gi();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'0';
	for(int i=1;i<=n;i++)c[i]=gi(),cnt0+=!c[i];
	if(n<=10){ans=0;dfs(1);return printf("%lld\n",ans),0;}
	if(n<=18){
		f[0][0][0]=1;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=std::min(i,m);j++){
				for(int S=0;S<(1<<n);S++){
					for(int k=1;k<=n;k++){
						if(S>>(k-1)&1)continue;
						if(i-j<c[k])inc(f[i+1][j+a[i+1]][S^(1<<k-1)],f[i][j][S]);
						else inc(f[i+1][j][S^(1<<k-1)],f[i][j][S]);
					}
				}
			}
		}
		//for(int j=m;j<=n;j++)std::cout<<f[n][j][(1<<n)-1]<<'\n';
		ans=0;for(int j=m;j<=n;j++)inc(ans,f[n][j][(1<<n)-1]);
		printf("%lld\n",ans);
		return 0;
	}
	if(n-cnt0+1<m)return puts("0"),0;
	if(chkA()){
		ans=1;for(int i=1;i<=n;i++)ans=ans*i%mod;
		return printf("%lld\n",ans),0;
	}
	puts("0");
	return 0;
}

