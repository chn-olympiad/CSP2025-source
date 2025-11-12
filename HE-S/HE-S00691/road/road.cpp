#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+3;
const ll inf=1e9+3;
inline ll read(){
	ll res=0;
	char c;c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
ll n,m,k;
struct node{
	ll u,v,w;
}g[maxn],gk[maxn];
ll f[maxn];
ll find(ll x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
ll c[maxn],val[13][maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		g[i].u=read(),g[i].v=read(),g[i].w=read();
	}
	sort(g+1,g+1+m,cmp);
	bool flag=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0)flag=0;
		for(int j=1;j<=n;j++){
			val[i][j]=read();
		}
	}
	ll ans=inf*n;
	if(flag){
		ans=0;
		for(int i=1;i<=n;i++)f[i]=i;
		ll tot=0;
		for(int i=1;i<=k;i++){
			f[n+i]=n+i;
			for(int j=1;j<=n;j++){
				tot++;
				g[m+tot]=node{n+i,j,val[i][j]};
			}
		}
		sort(g+1,g+1+m+tot,cmp);
		int sum=0;
		for(int i=1;i<=m+tot;i++){
			ll a=find(g[i].u),b=find(g[i].v);
			if(a!=b){
				f[a]=b;
				ans+=g[i].w;
				sum++; 
			}
			if(sum>=n+k-1)break;
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		bool flag=0;
		for(int j=1;j<=n;j++)f[j]=j;
		ll res=0;
		ll tot=0,cnt=0;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))==0)continue;
			res+=c[j];
			if(res>ans){
				flag=1;break;
			}
			cnt++;f[n+j]=n+j;
			for(int v=1;v<=n;v++){
				gk[++tot]=node{n+j,v,val[j][v]};
			}
		}
		if(flag)continue;
		sort(gk+1,gk+1+tot,cmp);
		ll sum=0;
		for(ll u=1,v=1;u+v<=m+tot;){
			if(res>ans){
				flag=1;break;
			}
			if((g[u].w<gk[v].w&&u<=m)||v>tot){
				ll a=find(g[u].u),b=find(g[u].v);
				if(a!=b){
					f[a]=b;
					res+=g[u].w;
					sum++; 
				}
				if(sum>=n+cnt-1)break;
				u++;
			}
			else{
				ll a=find(gk[v].u),b=find(gk[v].v);
				if(a!=b){
					f[a]=b;
					res+=gk[v].w;
					sum++; 
				}
				if(sum>=n+cnt-1)break;
				v++;
			}
		}
		if(flag)continue;
		ans=min(ans,res);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
