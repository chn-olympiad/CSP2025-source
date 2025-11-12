#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct road{
	int u;
	int v;
	ll w;
};
struct village{
	ll c;
	vector<ll> v;
};
village villages[15];
int n,m,k;
ll ans=1e18;
road roads[2000100];
int fa[11000];
void init_bcj(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}
int fi(int x){
	if(fa[x]==x){
		return x;
	}
	else{
		return fa[x]=fi(fa[x]);
	}
}
bool check(int x,int y){
	return fi(x)==fi(y);
}
void uni(int x,int y){
	fa[fi(x)]=fi(y);
}
bool cmp(road x,road y){
	return x.w<y.w;
}
void dfs(int x,vector<int> v){
	if(x==k+1){
		for(int i=0;i<v.size();i++){
			village vill=villages[v[i]];
			for(int j=0;j<n;j++){
				roads[m+i*n+j+1]={n+i+1,j+1,vill.v[j]};
			}
		}
		ll ansnow=0;
		for(int i=0;i<v.size();i++){
			ansnow+=villages[v[i]].c;
		}
		m+=v.size()*n;
		n+=v.size();
		init_bcj();
		sort(roads+1,roads+1+m,cmp);
		for(int i=1;i<=m;i++){
			road ro=roads[i];
			if(!check(ro.u,ro.v)){
				uni(ro.u,ro.v);
				ansnow+=ro.w;
			}
		}
		//cout<<"ansnow"<<' '<<ansnow<<endl;
		ans=min(ans,ansnow);
		n-=v.size();
		m-=v.size()*n;
		return ;
	}
	dfs(x+1,v);
	v.push_back(x);
	dfs(x+1,v);
}
int main(){
	ios::sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	if(k==0){
		ans=0;
		for(int i=1;i<=m;i++){
			cin>>roads[i].u>>roads[i].v>>roads[i].w;
		}
		sort(roads+1,roads+1+m,cmp);
		init_bcj();
		for(int i=1;i<=m;i++){
			road x=roads[i];
			if(!check(x.u,x.v)){
				uni(x.u,x.v);
				ans+=x.w;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m<=00000){
		for(int i=1;i<=m;i++){
			cin>>roads[i].u>>roads[i].v>>roads[i].w;
		}
		for(int i=1;i<=k;i++){
			cin>>villages[i].c;
			for(int j=1;j<=n;j++){
				ll ci;
				cin>>ci;
				villages[i].v.push_back(ci);
			}
		}
		dfs(1,{});
		cout<<ans;
		return 0;
	}
	else if(k>0){
		ans=0;
		for(int i=1;i<=m;i++){
			cin>>roads[i].u>>roads[i].v>>roads[i].w;
		}
		for(int i=1;i<=k;i++){
			int flag=0;
			cin>>villages[i].c;
			for(int j=0;j<n;i++){
				int ci;
				cin>>ci;
				if(!ci){
					flag=j+1;
				}
				villages[i].v[j]=ci;
			}
			for(int j=1;j<=n;j++){
				roads[m+j]={j,flag,villages[i].v[j-1]};
			}
			m+=n;
		}
		sort(roads+1,roads+1+m,cmp);
		init_bcj();
		for(int i=1;i<=m;i++){
			road x=roads[i];
			if(!check(x.u,x.v)){
				uni(x.u,x.v);
				ans+=x.w;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}


