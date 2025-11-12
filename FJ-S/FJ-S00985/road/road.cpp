#include<bits/stdc++.h>
using namespace std;
int n,m,fa[10005],c[15],sc[15][10005];
struct node{
	int u,v,w;
}s[3000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	return (fa[x]==x?x:(fa[x]=find(fa[x])));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int k,u,v,w,f=0;
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s[i].u,&s[i].v,&s[i].w);
	}for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&sc[i][j]);
	}if(k!=0)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				int cc=2147483647;
				for(int ii=1;ii<=k;ii++)cc=min(cc,sc[ii][i]+sc[ii][j]);
				s[++m].u=i,s[m].v=j,s[m].w=cc;
			}		
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(s[i].u),y=find(s[i].v);
		if(x!=y){
			fa[x]=y;
			ans+=s[i].w;
			f++;
		}if(f>=n-1)break;
	}
	cout<<ans;
	return 0;
} 

