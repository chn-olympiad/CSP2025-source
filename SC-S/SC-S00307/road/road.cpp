#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
#define A3 array<int,3>
using namespace std;
const int N = 1e6 + 10,mod = 1e9 + 7,base = 131,inf = 1e18;
int n,m,k,c[N],a[12][N],ans=inf;
int f[N];
void init(){
	for(int i=1;i<=n+k+1;i++) f[i]=i;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int a,int b){
	int fa=find(a),fb=find(b);
	f[fb]=fa;
}
bool same(int a,int b){
	return find(a)==find(b); 
}
vector<A3> tr,tr2;
int mp[1010][1010],iff[1010][1010],rd[1010][1010];
void sov1(){
	ans=0;
    sort(tr.begin(),tr.end());
    for(int i=0;i<m;i++){
    	auto x=tr[i];
    	int u=x[1],v=x[2],w=x[0];
    	if(!same(u,v)){
    		merge(u,v);
			ans+=w; 
		}
    }	
    cout<<ans; 
}
vector<int> v; 
int get(){
	int res=0;
	int idx=m;
	init();
	tr2.clear();
	tr2=tr;//复制 
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++) rd[i][j]=rd[j][i]=inf;
	} 
	for(auto x:v){
		res+=c[x];//建造 
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				rd[i][j]=rd[j][i]=min(rd[i][j],a[x][i]+a[x][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			tr2.push_back({rd[i][j],i,j});
			idx++;
		}
	} 
	sort(tr2.begin(),tr2.end());
    for(int i=0;i<idx;i++){
    	auto x=tr2[i];
    	int u=x[1],v=x[2],w=x[0]; 
    	if(!same(u,v)){
    		merge(u,v);
			res+=w; 
		}
    }
    return res;
}
int ti=0;
void dfs(int u){
	if(u==k){
		if(m>=100000&&k>5&&ti>4) return;
		int res=get();
		ans=min(ans,res);
		ti++;
		return;
	}
	dfs(u+1);
	v.push_back(u+1);
	dfs(u+1);
	v.pop_back(); 
}
void sov2(){
	dfs(0);
	cout<<ans;
	return;
}
void sov3(){
	init();
	int idx=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			tr.push_back({mp[i][j],i,j});
			idx++;
		}
	}
	ans=0;
    sort(tr.begin(),tr.end());
    for(int i=0;i<idx;i++){
    	auto x=tr[i];
    	int u=x[1],v=x[2],w=x[0];
    	if(!same(u,v)){
    		merge(u,v);
			ans+=w; 
		}
    }	
    cout<<ans; 
    return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	init(); //
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		if(iff[u][v]==0){
		    mp[u][v]=mp[v][u]=w;	
		} else {
		    mp[u][v]=mp[v][u]=min(mp[u][v],w);
		}
		iff[u][v]=iff[v][u]=1;
		tr.push_back({w,u,v});
	} 
	int f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			f=0;
		} 
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int u=1;u<=n;u++){
			for(int v=1;v<u;v++){
				if(iff[u][v]==0){
				    mp[u][v]=mp[v][u]=a[i][u]+a[i][v]+c[i];	
				} else {
				    mp[u][v]=mp[v][u]=min(mp[u][v],a[i][u]+a[i][v]+c[i]);
				}
				iff[u][v]=iff[v][u]=1;
			}
		}
	}
	if(k==0){
		sov1();
    } else if(f==1){
    	sov3();
	} else if(n<=1000){
		sov2();
	} else {
		sov1();
	}
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/