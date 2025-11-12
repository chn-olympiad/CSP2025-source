#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt,n,m,k,fa[10010],a[10010][10010],b[10010];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void help(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
	return ;
}
struct node{
	int x,y,w;
};
node nbr[1000010];
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=1e9;
		}
		a[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=min(a[x][y],z);
	}
	for(int o=1;o<=k;o++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a[i][j]=a[j][i]=min(a[i][j],c+b[i]+b[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt++;
			nbr[cnt].x=i,nbr[cnt].y=j,nbr[cnt].w=a[i][j];
		}
	}
	sort(nbr+1,nbr+1+cnt,cmp);
	int ans=0,o=0;
	for(int i=1;i<=cnt;i++){
		if(find(nbr[i].x)!=find(nbr[i].y)){
			help(nbr[i].x,nbr[i].y);
			o++;
			ans+=nbr[i].w;
			if(o==n-1){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
