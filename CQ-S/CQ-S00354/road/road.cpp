#include<bits/stdc++.h>
using namespace std;
struct note{
	int u,v,w;
}f[1000005];
int g[1000005];
int cmp(note x,note y){
	return x.w<y.w;
}
int s[10005],c[14],a[14][10005];
int find(int x){
	if(s[x]==x){
		return x;
	}
	s[x]=find(s[x]);
	g[s[x]]=min(g[s[x]],g[x]);
	return s[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,ans=1e9,cnt;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w; 
		f[i].u=u;
		f[i].v=v;
		f[i].w=w;
	}
	sort(f+1,f+n+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<(1<<k);i++){
	//	cout<<i<<":"<<endl;
		cnt=0;
		for(int j=1;j<=n;j++){
			g[j]=1e9;
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				cnt+=c[j];
				for(int l=1;l<=n;l++){
					g[l]=min(g[l],a[j][l]);
				}
			}
		}
		for(int j=1;j<=n;j++){
		//	cout<<g[j]<<" ";
		}
		for(int j=1;j<=n;j++){
			s[j]=j;
		}
		for(int j=1;j<=m;j++){
		//	cout<<f[j].u<<" "<<f[j].v<<" "<<f[j].w<<" "<<find(f[j].u)<<" "<<find(f[j].v)<<endl;
			if(find(f[j].u)!=find(f[j].v)){
				cnt+=min(g[find(f[j].u)]+g[find(f[j].v)],f[j].w);
			}
		}
	//	cout<<cnt<<endl;
		for(int j=1;j<=n;j++){
			g[j]=s[j]=0;
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
 	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
