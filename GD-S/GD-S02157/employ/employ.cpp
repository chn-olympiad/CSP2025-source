#include<cstdio>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const ll mod=998244353;
struct node{
	int v;
	ll cnt;
}a[505];
int cnt;
ll q[505];
ll n,m,k,z,x,s,p,ans,len,y;
ll f[2005][2005];
ll v[505],d[505];
ll tg[505];
ll c[2005][2005],jc[2005],inv[2005];
char ch[505];
bool bz[505];
void read(ll &x){
	char ch=getchar();
	x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return ;
}
ll mi(ll xx,ll ci){
	if(ci==0) return 1ll;
	ll po=mi(xx,ci>>1);po=po*po%mod;
	return (ci&1?po*xx%mod:po);
}
ll A(int xx,int yy){
	if(xx<yy) return 0;
	return jc[xx]*inv[xx-yy]%mod;
}
void dfs(int xx,int u){
	if(xx>n){
		if(u>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(bz[i]==1) continue;
		bz[i]=1;
		q[xx]=i;
		dfs(xx+1,u+(v[i]>d[xx]));
		bz[i]=0;
	}
	return ;
}
int main(){
	//employ
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	c[0][0]=1,jc[0]=1,inv[0]=1;
	for(int i=1;i<=n*4;i++){
		c[i][0]=1,jc[i]=jc[i-1]*i%mod,inv[i]=mi(jc[i],mod-2);
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){
		read(v[i]);
		v[i]=-v[i];
	}
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++) v[i]=-v[i],tg[v[i]]++;
	for(int i=n;i>=0;i--) tg[i]+=tg[i+1];
	int l=0;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+(ch[i]=='1');
		if(ch[i]=='1') cnt++;
	}
	for(int i=1;i<=n;i++) d[i]=i-d[i];
	for(int i=1;i*2<n;i++) swap(d[i],d[n-i+1]);
	a[1].cnt=1,a[1].v=d[1];
	l=1;
	for(int i=2;i<=n;i++){
		if(d[i]!=a[l].v) a[++l].v=d[i],a[l].cnt=0;
		a[l].cnt++;
	}
	if(cnt==n){
		if(tg[1]>=m) ans=jc[n];
	}
	else{
		dfs(1,0);
	}
	printf("%lld",ans);
	return 0;
}
