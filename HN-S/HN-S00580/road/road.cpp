#include<bits/stdc++.h>
using namespace std;
#define se second
#define fi first
long long M=4557430888798830399;
int const N=1e6+100;
int n,m,k,top,last[N],need,cost;
struct jgt{
	int last,from,to,value;
}e[2*N];
void add(int x,int y,int z){
	e[++top]={last[x],x,y,z};
	last[x]=top;
}
bool f[N];
int dis[N];
void bfs(){
	priority_queue<pair<int,pair<int,int> > > q;
	pair<int,pair<int,int> > it;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	f[1]=1;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=last[1];i;i=e[i].last){
		q.push({-e[i].value,{e[i].from,e[i].to}});
	}
	while(q.size()){
		it=q.top();
		q.pop();
		int ju=-it.fi;
		int from=it.se.fi;
		int to=it.second.second;
		if(ju+dis[from]>=dis[to]||f[to]) continue;
		dis[to]=dis[from]+ju;
		f[to]=1;
		need+=ju;
		for(int i=last[to];i;i=e[i].last){
			q.push({-e[i].value,{e[i].from,e[i].to}});
		}
	}
}
int a[1010][1010],b[11][10100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		bfs();
		cout<<need<<endl;
		return 0;
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=min(a[x][y],z);
		a[y][x]=min(a[y][x],z);
	}
	for(int l=1;l<=k;l++){
		cin>>b[l][n+1];
		for(int i=1;i<=n;i++){
			cin>>b[l][i];
		}
	}
	for(int l=1;l<=k;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i) a[i][j]=min(a[i][j],b[l][i]+b[l][j]+b[l][n+1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=M&&j!=i){
				add(i,j,a[i][j]);
			}
		}
	}
	bfs();
	cout<<need<<endl;
	return 0;
} 
