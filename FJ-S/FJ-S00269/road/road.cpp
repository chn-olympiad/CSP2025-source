#include<bits/stdc++.h>
using namespace std;
int f[100005];
struct st{
	int u;
	int v;
	int w;
	st(int _u,int _v,int _w):
		u(_u),v(_v),w(_w){}
};
vector<st>a;
int dis[1005][1005];
bool o(st x,st y){
	return x.w<y.w;
}
int e[100005];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
int main(){
	memset(dis,0x7f,sizeof(dis));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<100005;i++){
		f[i]=i;
	}
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int x,y,z;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x==y){
			continue;
		}
		if(x<y){
			if(z<dis[x][y]){
				dis[x][y]=z;
			}
		}
		else{
			if(z<dis[y][x]){
				dis[y][x]=z;
			}
		}
		
	}
	k+=m;
	for(int i=m;i<k;i++){
		scanf("%d",&x);
		for(int j=1;j<=n;j++){
			scanf("%d",&e[j]);
			for(int k=1;k<j;k++){
				long long tp=e[j]+e[k]+x;
				if(tp<dis[k][j]){
					dis[k][j]=tp;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			a.emplace_back(st(i,j,dis[i][j]));
		}
	}
	sort(a.begin(),a.end(),o);
	long long s=0;
	for(int i=0;i<m;i++){
		x=find(a[i].u);
		y=find(a[i].v);
		if(x-y){
			f[x]=y;
			s+=a[i].w;
			if(--n==1){
				break;
			}
		}
	}
	printf("%lld",s);
}
