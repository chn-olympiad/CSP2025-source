#include<bits/stdc++.h>
#define rd read()
#define ll long long
using namespace std;
inline int read()
{
	int x=0,ss=1,s=getchar();
	while((s<'0'||s>'9')&&s!='-')s=getchar();
	if(s=='-')ss=-1,s=getchar();
	while(s>='0'&&s<='9')x=x*10+s-'0',s=getchar();
	return x*ss;
}
const int N=18,M=(1<<18)+3,mod=998244353;string s;
int n,m,cnt,ans,c[M],fac[M];
bitset<M> vis,vs[N][N];int mp[N][N][M];
inline int dfs(int x,int res,int val)
{
	if(x-res>m-1)return fac[n-x];
	if(vs[x][res][val])return mp[x][res][val];
	if(x==n)return 0;int rs=0;
	for(int i=0;i<n;++i)
		if(((val>>i)&1)==0)
			if(s[x]=='0'||res>=c[i])(rs+=dfs(x+1,res+1,val|(1<<i)))%=mod;
			else (rs+=dfs(x+1,res,val|(1<<i)))%=mod;
	vs[x][res][val]=1;return mp[x][res][val]=rs;
}
signed main()
{
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	n=rd,m=rd;cin>>s;fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<n;++i)c[i]=rd;
	cout<<dfs(0,0,0)<<'\n';
	return 0;
}
