#include <bits/stdc++.h>
using namespace std;

struct node{
	int u,v,w;
	friend bool operator<(node a,node b){
		return a.w<b.w;
	}
};
const int N=1e6+5;
int n,m,k,ans;
int c[12],a[12][N];
node vt[N],v1[2*N];

int fa[N+12];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void mg(int x,int y){
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy;
}
bool check(int x,int y){
	return find(x)!=find(y);
}

int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vt[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	sort(vt+1,vt+m+1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,x=0;x<n-1;i++){
		if(check(vt[i].u,vt[i].v)){
			ans+=vt[i].w;
			mg(vt[i].u,vt[i].v);
			x++;
		}
	}
	if(k==0) cout<<ans;
	else{	
		for(int i=1;i<=pow(2,k)-1;i++){
			int sum=0,mm=m,nn=n;
			for(int j=1;j<=m;j++){
				v1[j]=vt[j];
			}
			for(int j=1;j<=k;j++){
				if((int(pow(2,k-1))&i)==i){
					sum+=c[j];
					nn++;
					for(int l=1;l<=n;l++){
						v1[l+mm]={n+j,l,a[j][l]};
					}
					mm+=n;
				}
			}
			sort(v1+1,v1+m+1);
			for(int i=1;i<=n+12;i++){
				fa[i]=i;
			}
			for(int i=1,x=0;x<n+nn-1;i++){
				if(check(v1[i].u,v1[i].v)){
					sum+=v1[i].w;
					mg(v1[i].u,v1[i].v);
					x++;
				}
			}
			ans=min(ans,sum);
		}
		cout<<ans;
	}
	return 0;
}
