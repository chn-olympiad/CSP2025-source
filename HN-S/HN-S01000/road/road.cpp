#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,fa[N],c[N],cnt;
struct node{
	int u,v,w;
}a[M];
int find(int x){return (fa[x]==x)?x:fa[x]=find(fa[x]);}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>c[j];
			c[j]+=x;
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				m++;
				a[m].u=u,a[m].v=v,a[m].w=c[u]+c[v]-x;
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			cnt+=a[i].w;
		}
	}
	cout<<cnt;
	return 0;
}

