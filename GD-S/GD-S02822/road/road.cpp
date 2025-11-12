#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
const int N=1e4+20;
struct edge{
	int u,v,w;
	bool operator<(const edge other)const{
		return w>other.w;
	}
}e[M];
int n,m,k,a[15][N],c[15],tot,cnt[N],ans,sum; 
int fa[N];
priority_queue<edge>q;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int nx,int ny){
	int fx=find(nx),fy=find(ny);
	if(fx!=fy) fa[fx]=fy;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		q.push(e[i]);
	}
	sum=n;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		tot=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				tot++;
				cnt[tot]=j;
			}
		}
		if(tot>1){
//			cout<<"!!"<<endl;
			for(int j=1;j<=tot;j++){
				for(int k=j+1;k<=tot;k++)
					merge(i,j),sum--;
			}
		}
		for(int j=1;j<=tot;j++){
			for(int k=1;k<=n;k++){
				if(a[i][k]==0) continue;
//				cout<<"!!"<<endl;
				q.push({cnt[j],k,a[i][k]});
			}
		}
	}
	while(!q.empty()){
		edge u=q.top();
		q.pop();
		if(find(u.u)==find(u.v)) continue;
		merge(u.u,u.v);
		sum--;ans+=u.w;
		if(sum<=1) break;
	}
	cout<<ans;
	return 0;
}
