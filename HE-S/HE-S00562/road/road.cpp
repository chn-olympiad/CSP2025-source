#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}e[1000010];
bool cmp(node a,node b){
	return a.z<b.z;
}
int fa[1000010],d[10010][10010],p[15],l[15][10010];
int fd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)d[i][j]=d[j][i]=2e9;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		d[x][y]=d[y][x]=min(d[x][y],z);
	}
	int mx=0;
	for(int i=1;i<=k;i++){
		cin>>p[i];
		mx=max(mx,p[i]);
		for(int j=1;j<=n;j++)scanf("%d",&l[i][j]);
	}
	if(mx==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int w=1;w<j;w++){
					d[j][w]=d[w][j]=min(d[j][w],l[i][j]+l[i][w]);
				}
			}
		}
		m=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(d[i][j]<=1e9)m++,e[m].x=i,e[m].y=j,e[m].z=d[i][j];
			}
		}
		sort(e+1,e+m+1,cmp);
		long long ans=0;
		int c=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int fx=fd(e[i].x),fy=fd(e[i].y);
			if(fx!=fy)fa[fx]=fy,ans+=e[i].z,c++;
			if(c==n-1)break;
		}
		cout<<ans;
	}else{
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int w=1;w<j;w++){
					d[j][w]=d[w][j]=min(d[j][w],l[i][j]+l[i][w]+p[i]);
				}
			}
		}
		m=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(d[i][j]<=1e9)m++,e[m].x=i,e[m].y=j,e[m].z=d[i][j];
			}
		}
		sort(e+1,e+m+1,cmp);
		long long ans=0;
		int c=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++){
			int fx=fd(e[i].x),fy=fd(e[i].y);
			if(fx!=fy)fa[fx]=fy,ans+=e[i].z,c++;
			if(c==n-1)break;
		}
		cout<<ans;
	}
	return 0;
}
