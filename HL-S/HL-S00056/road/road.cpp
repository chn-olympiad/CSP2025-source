#include<bits/stdc++.h> 
using namespace std;
int n,m,k; 
int c[1100];
bool vis[1100];
struct node{
	unsigned long long f,t,w;
}e[1700010];
int ss[11];
bool cmp(node x,node y){
	return x.w <y.w ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i].f =u;
		e[i].t =v;
		e[i].w =w;
	}
	for(int i=1;i<=k;i++){
		int q;
		cin>>q;
		c[i]=q;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e[(i-1)*n+j+m].f =i+n;
			e[(i-1)*n+j+m].t =j;
			e[(i-1)*n+j+m].w =w+q;
		}
	}
	unsigned long long minn=0x3f;
	

		sort(e+1,e+1+m+n*k,cmp);
		int cont=0;
		memset(vis,0,sizeof(vis));
		unsigned long long mi=0;
		
		for(int j=1;j<=m+n*k;j++){
			if(cont==n)	{
				for(int i=1;i<=k;i++){
					mi=mi-ss[i]*c[i];
				}
				cout<<mi;
				return 0;
			}
			
			if(!vis[e[j].f ]||!vis[e[j].t ]){
				if(!vis[e[j].f ]&&!vis[e[j].t ]){
					if(e[j].f<=n&&e[j].t<=n)	cont=cont+2;
					else if(e[j].f>n&&e[j].t>n)	cont=cont;
					else	cont=cont+1;
				}	
				else{
					if(!vis[e[j].f ]&&e[j].f<=n)	cont=cont+1;
					if(!vis[e[j].t ]&&e[j].t<=n)	cont=cont+1;
					
				}
				
				if(!vis[e[j].f ]&&e[j].f>n){
					for(int kk=1;kk<=k;kk++){
						if(e[j].f ==n+kk){
							ss[kk]++;
						}
					}
				}
				if(!vis[e[j].t ]&&e[j].t>n){
					for(int kk=1;kk<=k;kk++){
						if(e[j].t ==n+kk){
							ss[kk]++;
						}
					}
				}
				
				vis[e[j].f ]=vis[e[j].t ]=true;
				mi+=e[j].w ;
				
			}
		}
		minn=min(mi,minn);

	
	cout<<minn;
	return 0;
}
