#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=510;
int n,m,c[N];
char s[N];
ll jc[N];
void solve1(){
	for(int i=1;i<=n;i++){
		if(c[i]==0||s[i]=='0'){
			cout<<0;
			return ;
		}
	}
	cout<<jc[n];
}
bool check(){
	for(int i=1;i<=n;i++){
		if(s[i]=='0')return 0;
	}
	return 1;
}
ll f[N][N],g[N][N];
void solve2(){
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		memcpy(g,f,sizeof(f));
		memset(f,0,sizeof(f));
		for(int j=0;j<=i;j++){
			for(int k=0;k<=j;k++){
				if(j-k<c[i]){
					f[j][k]+=g[j][j]-g[j][k]+mod;
					if(!k)f[j][k]+=g[j][k]*(i-k);
					else f[j][k]+=(g[j][k]-g[j][k-1]+mod)*(i-k);
				}
				if(j&&k&&j>c[i]&&j-c[i]<=k){
					if(k==1)f[j][k]+=g[j-1][k-1]*(j-c[i]);
					else f[j][k]+=(g[j-1][k-1]-g[j-1][k-2]+mod)*(j-c[i]);
				}
				if(k)f[j][k]+=f[j][k-1];
				f[j][k]%=mod;
			}
		}
	}
	ll ans=0;
	for(int j=n-m;j>=0;j--)ans+=f[j][j];
	cout<<ans%mod;
}
bool vis[N];
int t[N],ans;
void dfs(int x){
	if(x==n+1){
		int num=0;
		for(int i=1;i<=n;i++){
			if(c[t[i]]<=num||s[i]=='0')num++;
		}
		if(num<=n-m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			t[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
void solve3(){
	dfs(1);
	cout<<ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	if(n==m)solve1();
	else if(n<=10)solve3();
	else if(check())solve2();
}