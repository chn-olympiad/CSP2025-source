#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,k,u,v,w,bol,bol1,c[20],a[20][11000],fa[11000],g,tol;
ll ans=1e18,ans1,sum;

struct data1{
	int v,w;
};

struct data2{
	int u,v,w;
	
	friend bool operator <(data2 x,data2 y){
		return x.w>y.w;
	}
}pp;

vector<data1> e[11000],f[11000];

int find(int u){
	return fa[u]^u ? fa[u]=find(fa[u]) : u;
}

ll solve(){
	sum=0;
	
	for (int i=1; i<=n+k; i++){
		fa[i]=i;
		
		for (int j=0; j<e[i].size(); j++){
			f[i].push_back(e[i][j]);
		}
	}
	
	priority_queue<data2> q;
	
	for (int i=1; i<=n+k; i++){
		for (int j=0; j<f[i].size(); j++){
			q.push({i,f[i][j].v,f[i][j].w});
		}
	}
	
	tol=1;
	
	while(tol<n+g){
		pp=q.top(); q.pop();
		
		if(find(pp.u)-find(pp.v)){
			fa[find(pp.v)]=find(pp.u);
			sum+=pp.w;
			tol++;
		}
	}
//	cout<<sum<<"\n";
	return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i=1; i<=m; i++)
		cin >> u >> v >> w,
		e[u].push_back({v,w}),
		e[v].push_back({u,w});
	
	for (int i=1; i<=k; i++){
		cin >> c[i];
		
		bol|=c[i];
		
		bol1=0;
		
		for (int j=1; j<=n; j++){
			cin >> a[i][j];
			
			if(!a[i][j] && !bol1){
				bol1=1;
				
//				b[i]=j;
			}
		}
		
		if(!bol1)  bol=1;
	}
	
	if(!bol){
//		for (int t=(1<<k)-1; t<1<<k; t++){
//			g=0;
			
//			for (int i=1; i<=n+k; i++)  f[i].clear();
			
			for (int i=1; i<=k; i++){
//				if((1<<k-1)&t){
//					g++;
					
					for (int j=1; j<=n; j++){
						f[n+i].push_back({j,a[i][j]});
						f[j].push_back({n+i,a[i][j]});
					}
//				}
			}
			
			g=k;
			
			ans=solve();
//		}
	}
	else {
		if(k>5)  k=5;
		
		for (int t=0; t<1<<k; t++){
			g=0,ans1=0;
			
			for (int i=1; i<=n+k; i++)  f[i].clear();
			
			for (int i=1; i<=k; i++){
				if((1<<i-1)&t){
					ans1+=c[i];
					
					g++;
					
					for (int j=1; j<=n; j++){
						f[n+i].push_back({j,a[i][j]});
						f[j].push_back({n+i,a[i][j]});
					}
				}
			}
			
			ans=min(ans,ans1+solve());
		}
	}
	
	cout << ans;
	
	return 0;
}
