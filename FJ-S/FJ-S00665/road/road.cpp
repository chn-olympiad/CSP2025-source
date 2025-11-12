#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,m,k,ans;
int vis[N],b[N],f[N];
int cnt;

struct node{
	int u,v,w;
}a[N];

bool cmp(node a1,node a2){
	return a1.w<a2.w;
}

int find(int p){
	if(f[p]==p)return p;
	return f[p]=find(f[p]);
}

void kruskal(){
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(find(a[i].u)!=find(a[i].v)){
			f[f[a[i].u]]=f[a[i].v];
			ans+=a[i].w;
			n--;
			if(n==1)return;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[++cnt]={u,v,w};
		a[++cnt]={v,u,w};
	}
	if(k==0){
		kruskal();
	}
	else{
		for(int i=1;i<=k;i++){
			int c;
			cin>>c;
			for(int j=1;j<=n;j++){
				int w;
				cin>>w;
				a[++cnt]={i+n,j,w};
			}
		}
		kruskal();
	}
	cout<<ans;
	return 0;
}
