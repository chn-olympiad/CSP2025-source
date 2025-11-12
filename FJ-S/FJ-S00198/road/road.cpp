#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+10;
const ll M=1e6+10;
const ll V=2e7+10;
struct node{
	ll x,y,v;
}a[M];
struct edge{
	ll ed,nxt,v;
}b[V];
ll n,m,k,f[N],cnt,ans,c[20],g[20][N],dis[N],vis[N],nbs[N],tot;
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool cmp(node p,node q){
	return p.v<q.v;
}
ll find(ll x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
void add(ll x,ll y,ll z){
	b[++tot].ed=y; b[tot].nxt=nbs[x]; nbs[x]=tot; b[tot].v=z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	for(ll i=1;i<=m;i++){
		a[i].x=read(); a[i].y=read(); a[i].v=read();
		add(a[i].x,a[i].y,a[i].v);
		add(a[i].y,a[i].x,a[i].v);
	}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(ll i=1;i<=n;i++) f[i]=i;
		for(ll i=1;i<=m;i++){
			ll x=a[i].x,y=a[i].y,v=a[i].v;
			ll p=find(x),q=find(y);
			if(p==q) continue;
//			cout<<x<<" "<<y<<" "<<v<<endl;
			f[p]=q;
			cnt++;
			ans+=v;
			if(cnt==n-1) break;
		}
		cout<<ans;
	}
	else if(n<=1000){
		for(ll i=1;i<=k;i++){
			c[i]=read();
			for(ll j=1;j<=n;j++) g[i][j]=read();
			for(ll j=1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					ll v=g[i][j]+g[i][k]+c[i];
					add(j,k,v); add(k,j,v);
				}
			}
		}
		memset(dis,0x3f,sizeof(dis));
		dis[1]=0;
		for(ll i=1;i<=n;i++){
			ll l=0;
			for(ll j=1;j<=n;j++){
				if(!vis[j] && dis[j]<dis[l]) l=j;
			}
			vis[l]=1;
			ans+=dis[l];
			for(ll x=nbs[l];x;x=b[x].nxt){
				ll u=b[x].ed,v=b[x].v;
				dis[u]=min(dis[u],v);
			}
		}
		cout<<ans;
	}
	else{
		ll t=m;
		for(ll i=1;i<=k;i++){
			c[i]=read();
			ll p=0;
			for(ll j=1;j<=n;j++){
				g[i][j]=read();
				if(g[i][j]==0) p=j;
			}
			for(ll j=1;j<=n;j++){
				if(j==p) continue;
				a[++t].x=p; a[t].y=j; a[t].v=g[i][j];
			}
		}
		sort(a+1,a+t+1,cmp);
		for(ll i=1;i<=n;i++) f[i]=i;
		for(ll i=1;i<=t;i++){
			ll x=a[i].x,y=a[i].y,v=a[i].v;
			ll p=find(x),q=find(y);
			if(p==q) continue;
//			cout<<x<<" "<<y<<" "<<v<<endl;
			f[p]=q;
			cnt++;
			ans+=v;
			if(cnt==n-1) break;
		}
		cout<<ans;
	}
	return 0;
}
