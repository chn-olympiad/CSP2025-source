#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;

struct edge{
	int u,v,w;
}e[1000010];

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int c[15],comp[15],a[15][10010],fa[10010],b[1000010];

int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]);
}

void onion(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++) fa[i]=i;
	
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m&&cnt<n;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		printf("%d city and %d city is already OK!But...price is %d.\n",u,v,w);
		ans+=w;onion(u,v);b[i]=1;cnt++;
	}
	
	if(k) 
	for(int i=1;i<=m;i++){
		if(b[i]){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			for(int j=1;j<=k;j++){
				int d=a[j][u]+a[j][v];
				if(!comp[j]) d+=c[j];
				if(d<w){
					ans=ans-w+d;
					if(!comp[j]) comp[j]=1;
				}
			}
		}
	}
	
	cout<<ans;
	return 0;
}
