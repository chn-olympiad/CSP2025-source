#include<bits/stdc++.h>
#define ff(i,n) for(int i=1;i<=n;i++)
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define int long long
using namespace std;
const int N=500+10,M=2e6+10,mod=998244353;
int i,j,n,m,k,x,y,tot,z;
char s[N];
int sum[N],f[N][N],fac[N],a[N],ans;
bool v[N],b[N];
int in(){
	int w=1,res=0;
	char c;
	c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')w=-w;
		c=getchar();
	}
	while(('0'<=c&&c<='9')){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*w;
}
void dfs(int x,int cnt){
	if(cnt>=m){
		ans=(ans+fac[n-x+1])%mod;
//		cout<<n-x+1;
		return;
	}
	if(x>n||cnt+(n-x+1)<m)return;
	ff(i,n){
		if(!v[i]){
			v[i]=1;
			dfs(x+1,cnt+(x-1-cnt<a[i]&&b[x]));
			v[i]=0;
		}
	}
}
main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char c;
	fac[0]=1;
	ff(i,n)fac[i]=fac[i-1]*i%mod;
	ff(i,n){
		cin>>c;
		b[i]=(c=='1');
	}
	ff(i,n)a[i]=in();
	dfs(1,0);
	cout<<ans;
}
