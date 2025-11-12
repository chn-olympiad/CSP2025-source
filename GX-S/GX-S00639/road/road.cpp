#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct s{ll u;ll v;ll w;};
const s GUNMU={-1,-1,-1};
int n,m,k;int u,v,w;
//ll side[10005][10005];
s side[1000005];
ll c[15][10005];
int city[10005];

bool cmpw(s a,s b){
	return (a.w<b.w);
}

int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=0;i<1000005;i++){side[i]=GUNMU;}
	for(int i=0;i<10005;i++){city[i]=i;}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		side[i]={min(u,v),max(u,v),w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}

	//i am going to kruskal!
	//no town:
	int ss=0;//ss==n-1!!!
	int total=0;
	int pa;

	sort(side+1,side+m+1,cmpw);
	for(int i=1;i<=m;i++){
		if(ss==n-1)break;
		if(city[side[i].u]!=city[side[i].v]){
			//cout<<"connected "<<side[i].u<<" and "<<side[i].v<<endl;
			ss++;
			total+=side[i].w;
			pa=city[side[i].u];
			while(pa!=city[pa]){pa=city[pa];}
			city[side[i].v]=pa;
		}
	}

	cout<<total<<endl;

	return 0;
}
