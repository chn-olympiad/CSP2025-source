#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
#define llt long long
int n,m,c[N],f[N],dlc,dlck;
llt fac[N],ans;
bitset<N>a,vis;
inline void solve(int res=0)
{
	for(int i=1,s=0;i<=n;i++)
	{
		if(s>=c[f[i]]) s++;
		else s+=(!a[i]),res+=a[i];
//		cout<<f[i]<<"  "<<s<<' '<<res<<"   ";
	}
//	cout<<endl;
	ans+=(res>=m);
}
void dfs(int p)
{
	if(p>n) {solve();return;}
	for(int i=1;i<=n;i++) if(!vis[i]){vis[i]=1;f[p]=i;dfs(p+1);vis[i]=0;}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		if(c!='0'&&c!='1') i--;
		else a[i]=c-'0',dlc+=c-'0';
	}
//	for(int i=1;i<=n;i++) cout<<a[i];cout<<endl;
//	cout<<dlc<<endl;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),dlck+=(c[i]==0);
	if(n<=10) {dfs(1);printf("%lld",ans);return 0;}
	else if(dlc<m) {putchar('0');return 0;}
	else if(dlc==n) {printf("%lld",fac[n]%mod);return 0;}
	else {dfs(1);printf("%lld",ans);return 0;}
	return 0;
}
/*
3 2
101
1 1 2
*/
