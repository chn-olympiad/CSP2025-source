#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll u,v,w;
};
ll n,m,k;
ll fa[10005];
node a[1000005];
void pre(){
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
}
ll find(ll x){
	if(fa[x]==x){
		return fa[x];
	}
	else{
		return find(fa[x]);
	}
}
void unite(ll x,ll y){
	if(find(x)==find(y)){
		return ;
	}
	else{
		fa[find(x)]=find(y);
	}
}

bool cmp(node a,node b){
	return a.w<b.w;
	
}
ll ans;
ll cnt;
ll sum;
void kruskal(){
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;++i){
		ll uu=a[i].u,vv=a[i].v;
		if(find(uu)==find(vv)){
			continue;
		}
		else{
		    unite(uu,vv);
		    sum=find(uu);
		    ans+=a[i].w;
		    cnt++;
		}
	}
	
}
vector<node> g;
ll c[15];
ll s[15][10005];
bool suba=true;
bool vis[15]={false};
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	pre();
	for(int i=1;i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	
	
	for(int i=1;i<=m;++i){
		
			g.push_back({a[i].u,a[i].v,a[i].w});
		
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i]!=0){
			suba=false;
		}
		for(int j=1;j<=n;++j){
			cin>>s[i][j];
			if(s[i][j]!=0){
				suba=false;
			}
		}
	}
	
	for(auto l:g){
		if(l.u<=k){
			if(!vis[l.u]){
				if(c[l.u]+s[l.u][l.v]<=l.w){
					vis[l.u]=1;
					l.w=s[l.u][l.v];
				}
			}
			else{
				if(s[l.u][l.v]<=l.w){
					l.w=s[l.u][l.v];
				}
			}
			cout<<l.w<<"\n";
			
		}
		if(l.v<=k){
			if(!vis[l.v]){
				if(c[l.v]+s[l.v][l.u]<=l.w){
					vis[l.v]=1;
					l.w=s[l.v][l.u];
				}
			}
			else{
				if(s[l.v][l.u]<=l.w){
					l.w=s[l.v][l.u];
				}
			}
			cout<<l.w<<"\n";
		}
		
	}
	ll cntt=0;
	for(auto l:g){
		cntt++;
		a[cntt].u=l.u;
		a[cntt].v=l.v;
		a[cntt].w=l.w;
		cout<<a[cntt].w<<" ";
	}
	
	kruskal();
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
