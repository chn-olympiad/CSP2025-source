//GZ-S00140 贵州省织金育才学校 宋载航 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const ll N=1e4+19,M=1e6+9,INF=0x3f3f3f3f3f3f3f3f;
ll read(){
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return f*x;
}
void print(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
ll T=1;
ll n,m,k;
struct edge{
	ll u,v,w;
}e[M*2],ee[M*2];
ll con[19][N],fa[N],ans=INF;
ll get(ll t){
	if(fa[t]==t) return t;
	return fa[t]=get(fa[t]);
}
vector<edge> g; 
void dfs(ll now,ll sum,ll num){
	if(now==k+1){
		for(int i=1;i<=m;i++){
			ee[i]=e[i];
		}
		for(int i=0;i<g.size();i++){
			ee[m+i+1]=g[i];
		}
		ll mm=m+g.size();
		sort(ee+1,ee+mm+1,[](edge p,edge q)->bool{
			return p.w<q.w;	
		});
		ll mst=0,cnt=0;
		for(int i=1;i<=n+num;i++){
			fa[i]=i;
		}
		for(int i=1;i<=mm;i++){
			ll uu=get(ee[i].u),vv=get(ee[i].v);
			if(uu==vv){
				continue;
			}
			fa[uu]=vv;
			mst+=ee[i].w;
			cnt++;
			if(cnt==n+num-1){
				break;
			}
		}
		ans=min(ans,mst+sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		g.emplace_back((edge){n+num+1,i,con[now][i]});
	}
	dfs(now+1,sum+con[now][0],num+1);
	for(int i=1;i<=n;i++){
		g.pop_back();
	}
	dfs(now+1,sum,num);
}
inline void solve(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	bool fla=1;
	for(int i=1;i<=k;i++){
		bool fl=0;
		for(int j=0;j<=n;j++){
			con[i][j]=read();
			if(con[i][j]==0){
				fl=1;
			}
		}
		if(fl==0||con[i][0]!=0){
			fla=0;
		}
	}
	if(k<=0){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(e+1,e+m+1,[](edge p,edge q)->bool{
			return p.w<q.w;	
		});
		ll mst=0;
		for(int i=1;i<=m;i++){
			ll uu=get(e[i].u),vv=get(e[i].v);
			if(uu==vv){
				continue;
			}
			fa[uu]=vv;
			mst+=e[i].w;
		}
		print(mst);
	}
	else{
		if(fla){
			ll mm=m;
			for(int i=1;i<=n+k;i++){
				fa[i]=i;
			}
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(con[i][j]==0){
						ll uu=get(i),vv=get(j);
						if(uu!=vv){
							fa[uu]=vv;
						}
					}
					else{
						mm++;
						e[mm].u=i;
						e[mm].v=j;
						e[mm].w=con[i][j];
					}
				}
			}
			sort(e+1,e+mm+1,[](edge p,edge q)->bool{
				return p.w<q.w;	
			});
			ll mst=0;
			for(int i=1;i<=mm;i++){
				ll uu=get(e[i].u),vv=get(e[i].v);
				if(uu==vv){
					continue;
				}
				fa[uu]=vv;
				mst+=e[i].w;
			}
			print(mst);
		}
		else{
			dfs(1,0,0);
			print(ans);
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	while(T--){
		solve();
	}
	return 0;
}

