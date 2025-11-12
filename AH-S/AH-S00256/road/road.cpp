#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,g,flag;
};
int n,m,k,l[15][100005],f[100005],vis[15],x[15];
bool cmp(node a,node b){
	return a.g<b.g;
}
vector<node> v;
int cnt=0;
void merge(int x,int y){
	if(f[x]==0&&f[y]==0){
		f[x]=f[y]=++cnt;
		return;
	}
	if(f[x]==0&&f[y]!=0){
		f[x]=f[y];
		return;
	}
	if(f[y]==0&&f[x]!=0){
		f[y]=f[x];
		return;
	}
	int la=f[y];
	for(int i=1;i<=n;i++){
		if(f[i]==la){
			f[i]=f[x];
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,vr,g;
		scanf("%d%d%d",&u,&vr,&g);
		v.push_back({u,vr,g,0});
	}
	x[0]=0;
	for(int i=1;i<=k;i++){
		cin>>x[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&l[i][j]);
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				v.push_back({j,k,l[i][j]+l[i][k]+x[i],i});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	long long ans=0;
	int cn=0;
	for(node e:v){
		int u=e.u;
		int v=e.v;
		int w=e.flag;
		if(f[u]==f[v]&&f[u]!=0&&f[v]!=0)continue;
		else{
			cn++;
			merge(u,v);
			ans+=e.g;
			if(vis[w]==0){
				vis[w]=1;
			}else{
				ans-=x[w];
			}
		}
		if(cn==n-1)break;
	}
	cout<<ans<<endl;
	return 0;
} 
/*4 4 2
  1 4 6
  2 3 7
  4 2 5
  4 3 4
  1 1 8 2 4
  100 1 3 2 4
 */
