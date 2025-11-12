#include<bits/stdc++.h>
using namespace std;
#define LL long long
int vis[10005],zt[10005],n,m,k,u,v,w,d,dis[10005],vq[10005];
LL ans;
struct rd{
	int y,z;
};
struct nw{
	int w,m[10005];
}a[15];
vector<rd> r[10005];
struct qu{
	int a,b;
	friend bool operator<(qu qw,qu we){
		if(qw.b!=we.b) return qw.b>we.b;
		return 1;
	}
}uu;
priority_queue<qu> q;
void sr(){
	q.push({1,0});
	vis[1]=0;
	while(!q.empty()){
		uu=q.top();
		q.pop();
		if(vis[uu.a]!=uu.b||vq[uu.a]) continue;
		ans=(LL)(ans+uu.b);
		vq[uu.a]=1; 
//		cout<<r[uu.a].size();
//		cout<<uu.a<<" "<<uu.b<<"\n";
		for(int i=0;i<r[uu.a].size();i++) if(vis[r[uu.a][i].y]>r[uu.a][i].z&&!vq[r[uu.a][i].y]){
			q.push({r[uu.a][i].y,r[uu.a][i].z});
			vis[r[uu.a][i].y]=r[uu.a][i].z;
//			cout<<r[]
//			cout<<"!!!";
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		r[u].push_back({v,w});
		r[v].push_back({u,w});
	}
	zt[0]=1;
	if(k==0){
		for(int i=1;i<=n;i++) vis[i]=1e9+5;
		sr();
		cout<<ans;
	}
//	for(int i=1;i<=k;i++){
//		cin>>a[i].w;
//		for(int j=1;j<=n;j++){
//			cin>>a[i].c[j];
//			r[i].push_back({j,a[i].c[j],i});
//			r[j].push_back({i,a[i].c[j],i});
//		}
//	}
//	for(int i=0;i<(1<<k);i++){
//		for(int j=1,l=i;j<=k;j++,l/=2) zt[j]=l%2;
//		for(int j=1;j<=n;j++) dis[j]=1e17;
//		sr();		
//	}
	return 0;
}
/*
5 6 0
1 2 1000000000
1 3 1000000000
2 3 1000000000
2 4 1000000000
3 5 1000000000
4 5 1000000000
*/
