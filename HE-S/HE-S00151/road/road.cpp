#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
#define int long long
int n,m,k;
int u[N],a[15][1010000][5],p[N];
struct node{
	int u,v,w;
	bool friend operator<(node a,node b){
		return a.w<b.w;
	}
}e[N];
int find(int x){
	if(u[x]==x){
		return x;
	}
	return u[x]=find(u[x]);
}
void merge(int x,int y){
	if((x=find(x))!=(y=find(y))){
		u[x]=y;
	}
}
signed main(){
	//cout<<1111;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			u[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e+1,e+m+1);
		int ans=0;
		for(int i=1;i<=m;i++){
			if(find(e[i].u)!=find(e[i].v)){
				ans+=e[i].w;
				merge(e[i].u,e[i].v);
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			u[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		int tot=0;
		for(int i=1;i<=k;i++){
			int x;
			cin>>x;
			p[i]=x;
			
			for(int j=1;j<=n;j++){
				int y;
				cin>>y;
				a[i][j][1]=n+i;
				a[i][j][2]=j;
				a[i][j][3]=y;
				tot++;
				e[m+tot].u=n+i;
				e[m+tot].v=j;
				e[m+tot].w=y;
			}
		}
		sort(e+1,e+m+tot+1);
		int ans=0;
		for(int i=1;i<=m;i++){
			if(find(e[i].u)!=find(e[i].v)){
				ans+=e[i].w;
				merge(e[i].u,e[i].v);
			}
		}
		int flag=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=p[i];j++){
				int x=a[i][j][1],y=a[i][j][2];
				u[x]=x;
				u[y]=y;
				for(int k=2;k<=n;k++){
					if(find(1)!=find(k)){
						flag=1;
					}
				}
				if(!flag){
					ans-=a[i][j][3];
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
4 4 1
1 2 1
1 3 2
2 3 5
1 2 1
0 5 0 0
*/
