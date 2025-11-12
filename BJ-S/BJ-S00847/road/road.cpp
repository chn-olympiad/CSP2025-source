#include<bits/stdc++.h>
using namespace std;

struct node{
	int u,v,w;
}ed[1000050];
int n,m,k;
int g[1050][1050],mem[1050][1050],fa[1000050];
int mer[1000500],ct[1000050];
int read(){
	int x=0,f=1;
	char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	return x*f;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for (int i=1;i<=n+k;i++)fa[i]=i;
	for (int i=1;i<=m;i++){
		++cnt;
		cin>>ed[cnt].u>>ed[cnt].v>>ed[cnt].w;
		mem[ed[cnt].u][ed[cnt].v]=cnt;
		//++cnt;ed[cnt].u=ed[cnt-1].v;ed[cnt].v=ed[cnt-1].u;ed[cnt].w=ed[cnt-1].w;
		//mem[ed[cnt].u][ed[cnt].v]=cnt;
		g[ed[cnt].u][ed[cnt].v]=ed[cnt].w;//g[ed[cnt].v][ed[cnt].u]=ed[cnt].w;
	}
	int ci;
	for (int i=1;i<=k;i++){
		cin>>ci;
		for (int j=1;j<=n;j++){
			ed[++cnt].u=n+i;ed[cnt].v=j;cin>>ed[cnt].w;
			mem[ed[cnt].u][ed[cnt].v]=cnt;
			//ed[++cnt].u=j;ed[cnt].v=n+i;ed[cnt].w=ed[cnt-1].w;
			//mem[ed[cnt].u][ed[cnt].v]=cnt;
			g[n+i][j]=ed[cnt].w;//g[j][n+i]=ed[cnt].w;
		}
		for(int j=1;j<=n;j++){
			for (int k=1;k<j;k++){
				if(g[j][k]!=0&&g[j][k]<g[n+i][j]+g[j][n+i]){
					ed[mem[n+i][j]].w=1000000008;
					//ed[mem[j][n+i]].w=1000000008;
				}
			}
		}
	}
	sort(ed+1,ed+cnt+1,cmp);

	//for (int i=1;i<=cnt;i++){
	//	cout<<ed[i].u<<" "<<ed[i].v<<" "<<ed[i].w<<endl;
	//}
	long long ans=0;
    for(int i=1;i<=cnt;i++){
		if(find(ed[i].u)!=find(ed[i].v)){
			if(ed[i].u>n){ct[ed[i].u]++;mer[ed[i].u]=ed[i].w;}
			if(ed[i].v>n){ct[ed[i].v]++;mer[ed[i].v]=ed[i].w;}
			//cout<<ed[i].u<<" "<<ed[i].v<<endl;
			fa[find(ed[i].u)]=ed[i].v;
			ans+=ed[i].w;
		}
	}
	for(int i=n+1;i<=n+k;i++){
		if(ct[i]==1)ans-=mer[i];
	}
	cout<<ans;
    return 0;
}
