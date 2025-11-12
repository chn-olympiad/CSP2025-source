#include <iostream>
#include <algorithm>
#define ll long long
#define R(a,b,c) for(ll a=b;a<=c;a++)
#define E(a,b,c) for(ll a=b;a>=c;a--)
using namespace std;
struct node{
	ll u,v,w; 
};
bool operator <(node a,node b){
	return a.w<b.w;
}
ll read(){
	ll x=0; 
	char c=getchar();
	while(!(c>='0'&&c<='9'))c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
node g[1100025];
node g2[1100025];
node g3[1100025];
ll cnt=0;
ll cnt2=0;
ll fa[20025];
ll p[15];
ll a[15][20025];
ll c[20025];
bool is[15];
inline ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
inline int merge(ll x,ll y){
	x=find(x);
	y=find(y);
	fa[x]=y;
	return 0;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n=read(),m=read(),k=read();
	R(i,1,m){
		g[i].u=read();
		g[i].v=read();
		g[i].w=read();
	}
	R(i,1,n+k)fa[i]=i;
	sort(g+1,g+1+m);
	ll ans=0;
	R(i,1,m){
		ll u=g[i].u,v=g[i].v;
		if(find(u)==find(v))continue;
		merge(u,v);
		g2[++cnt]=g[i];
		ans+=g[i].w;
	}
	R(i,1,k){
		c[i]=read();
		R(j,1,n)a[i][j]=read(); 
	}
	ll CNT=0;
	R(i,0,(1<<k)-1){
		if(CNT>3.5e6)break;
		R(j,1,cnt)g[j]=g2[j];
		ll ncnt=cnt;
		R(t,1,k)if(i&(1<<t-1))R(j,1,n){
			g[++ncnt]={t+n,j,a[t][j]};
			CNT++;
		}
		sort(g+1,g+1+ncnt);
		ll ns=0;
		R(j,1,n+k)fa[j]=j;
		R(j,1,k)is[j]=0;
		R(j,1,ncnt){
			CNT++;
			ll u=g[j].u,v=g[j].v;
			if(find(u)==find(v))continue;
			merge(u,v);
			if(u>n&&!is[u-n]){
				is[u-n]=1;
				ns+=c[u-n];
			}
			if(v>n&&!is[v-n]){
				is[v-n]=1;
				ns+=c[v-n];
			}	
			ns+=g[j].w;
			if(ns>=ans)break;
		}
		if(ns<ans)ans=ns;
	}
//	cout<<CNT<<'\n';
//cout<<ans<<'\n'; 
	R(i,1,k)p[i]=i;
	R(T,1,10){
		R(i,1,k){
			R(j,1,cnt)g[j]=g2[j];
			R(j,1,n)g[j+cnt]={p[i]+n,j,a[p[i]][j]};
			sort(g+1,g+1+n+cnt);
			ll ns=0;
			R(i,1,n+k)fa[i]=i;
			R(i,1,k)is[i]=0;
			cnt2=0;
			R(j,1,n+cnt){
				ll u=g[j].u,v=g[j].v;
				if(find(u)==find(v))continue;
				merge(u,v);
				g3[++cnt2]=g[j];
				if(u>n&&!is[u-n]){
					is[u-n]=1;
					ns+=c[u-n];
				}
				if(v>n&&!is[v-n]){
					is[v-n]=1;
					ns+=c[v-n];
				}	
				ns+=g[j].w;
				if(ns>=ans)break;
			}
			if(ns<ans){
				ans=ns;
				cnt=0;
				R(j,1,cnt2)g2[++cnt]=g3[j];
			}
		}
		random_shuffle(p+1,p+1+k);
	}
	cout<<ans<<'\n';
	return 0;
}
//15:17 wa 4
//16:30 tiao
