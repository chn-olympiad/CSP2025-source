#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=1e4+10;
const ll M=1e6+10;
ll n,m,k;
ll ans=1e18,cnt,top,sum,tmp;
struct Node{
	ll u,v,w;
	friend bool operator<(Node x,Node y){
		return x.w<y.w;
	}
}e[1100010];
ll fa[10020];
bool vis[20];
ll c[20];
bool special_A=true;
ll find(ll t){
	return fa[t]==t?t:fa[t]=find(fa[t]);
}
void calc(ll t){
	sum=cnt=0;
	tmp=n;
	for (int i=1;i<=k;i++) if((t>>(i-1))&1) tmp++,sum+=c[i];
	if(sum>ans) return;
	for (int i=1;i<=n+k;i++) fa[i]=i;
	for (int i=1;i<=top;i++){
		if(e[i].u>n&&(!((t>>(e[i].u-n-1))&1))) continue;
		ll uu=find(e[i].u);
		ll vv=find(e[i].v);
		if(uu==vv) continue;
		fa[uu]=vv;
		sum+=e[i].w;
		cnt++;
		if(cnt==tmp-1) break;
	}
	ans=min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for (int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	top=m;
	for (int i=1;i<=k;i++) {
		c[i]=read();
		if(c[i]) special_A=false;
		for (int j=1;j<=n;j++) {
			e[++top].u=n+i;
			e[top].v=j;
			e[top].w=read();
		}
	}
	sort(e+1,e+1+top);
	if(special_A) calc((1<<k)-1);
	else for (int i=0;i<(1<<k);i++) calc(i);
	printf("%lld\n",ans);
	return 0;
}
