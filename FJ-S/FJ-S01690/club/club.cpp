#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#define gc()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define FIN(x) freopen(x".in","r",stdin);
#define FOUT(x) freopen(x".out","w",stdout);
#define ll long long
#define pll pair<ll,ll>
#define il inline
#define re register int
#define rl register ll
using namespace std;
const ll MN=1e5+5,INF=1ll*2132239043*13431314;
ll n,a[MN][4],minn[MN],maxn[MN],ans,t[4],p;
priority_queue<ll,vector<ll>,greater<ll> >q;
char buf[1<<23],*p1=buf,*p2=buf;
il ll read(){ll x=0,f=1;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=gc();}return x*f;}
il void write(rl x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
il ll gs(rl x){return 6-minn[x]-maxn[x];}
il ll gs2(rl x){return a[x][1]+a[x][2]+a[x][3]-a[x][minn[x]]-a[x][maxn[x]];}
il void solve(){
	n=read();ans=t[1]=t[2]=t[3]=p=0;
	while(!q.empty()) q.pop();
	for(re i=1; i<=n; ++i) minn[i]=maxn[i]=0;
	for(re i=1; i<=n; ++i) for(re j=1; j<=3; ++j){
		a[i][j]=read();
		if(!minn[i]||a[i][minn[i]]>=a[i][j]) minn[i]=j;
		if(!maxn[i]||a[i][maxn[i]]<=a[i][j]) maxn[i]=j;
	}
	for(re i=1; i<=n; ++i) ans+=a[i][maxn[i]],t[maxn[i]]++;
	for(re i=1; i<=3; ++i) if(t[i]>n/2){p=i;break;}
	if(!p){write(ans);putchar('\n');return;}
	for(re i=1; i<=n; ++i) if(maxn[i]==p) q.push(a[i][maxn[i]]-gs2(i));
	for(re i=1; i<=t[p]-n/2; ++i) ans-=q.top(),q.pop();
	write(ans);putchar('\n');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	// ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll T=read();while(T--)solve();
	return 0;
}//251101 CSP2025 RP++
