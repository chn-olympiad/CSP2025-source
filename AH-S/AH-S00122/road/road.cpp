#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,l=1,cnt,qwe,book[3000];
int g[3000][3000];
struct node{
	int u,v,w;
}q[9000000];
bool cmp(node x,node y){
	return x.w<y.w;
}
void dfs(int x,int y,int xx,int yy){
	for(int i=1;i<=n+k;i++){
		if(g[x][i]==1&&book[i]!=1){
			book[i]=1;
			g[xx][i]=1;
			g[i][xx]=1;
			dfs(i,y,xx,yy);
			book[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x;
	for(int i=1;i<=m;i++){
		cin>>q[i].u>>q[i].v>>q[i].w;
	}	
	for(int i=1;i<=k;i++){
		cin>>x;
		int minn=0x3f3f3f3f,d=0;
		for(int j=1;j<=n;j++){
			cin>>q[m*i+j].w;
			if(minn>q[m*i+j].w){
				minn=q[m*i+j].w;
				d=m*i+j;
			}
			q[m*i+j].u=m+i;
			q[m*i+j].v=j;
		}
		q[d].w+=x;
	}
	sort(q+1,q+1+n+m*k,cmp);
	for(int i=1;i<=n+m*k;i++){
		qwe=0;
		if(g[q[i].u][q[i].v]==1){
			continue;
		}
		g[q[i].u][q[i].v]=1;
		g[q[i].v][q[i].u]=1;
		dfs(q[i].u,q[i].v,q[i].u,q[i].v);
		cnt=cnt+q[i].w;
		for(int x=1;x<=n;x++){	
			qwe=0;
			for(int j=1;j<=n;j++){
				if(g[x][j]==0){
					qwe=1;
					break;
				}
			}
			if(!qwe){
				break;
			}
		}
		if(!qwe){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
