#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+30;
const int M=1e4+10;
struct node{
	int u,v,w;
}edge[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int n,m,k;
int p[N];
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
int a[20][M];
int c[20];
int sz[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	int num=m;
	int tot=n;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	/*for(int i=1;i<=k;i++){
		cin>>c[i];
		//int minn=0x3f3f3f3f,id;
		++tot;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			edge[++num].u=tot;
			edge[num].v=j;
			edge[num].w=a[i][j]+c[i];
			//minn=min(a[i][j],minn);
			//if(minn==a[i][j]) id=j;
		}
	}*/

	for(int i=1;i<=k;i++){
		cin>>c[i];
		++tot;
		int minn=0x3f3f3f3f,id;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			edge[++num].u=tot;
			edge[num].v=j;
			edge[num].w=a[i][j];
			minn=min(a[i][j],minn);
			if(minn==a[i][j]) id=num;
		}
		edge[id].w+=c[i];
	}
	for(int i=1;i<=tot;i++){
		p[i]=i;
		sz[i]=1;
		if(i>n) sz[i]=0;
	}
	sort(edge+1,edge+1+num,cmp);
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=num;i++){
		int uu=find(edge[i].u);
		int vv=find(edge[i].v);
		if(vv==uu) continue;
		p[uu]=vv;
		sz[vv]+=sz[uu];
		cnt++;
		ans+=edge[i].w;
		if(sz[vv]==n) break;
	}
	cout<<ans<<"\n";
	return 0;
}
