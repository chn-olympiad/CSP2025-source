#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,m,k;
struct node{
	int u,v,w;
}edge[N];
int c[15],vis[15],flag[15],fa[N];
int edge2[15][10005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fnd(int x){
	if(fa[x]==x)return x;
	else return fa[x]=fnd(fa[x]);
}
int solve(){
	long long sum=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		node p=edge[i];
		int fau=fnd(p.u);
		int fav=fnd(p.v);
		if(fau==fav)continue;
		int tmp=p.w,last=0,nopay=0;
		for(int i=1;i<=k;i++){
			flag[i]=0;
			if(vis[i]==0)flag[i]=1;
			if(flag[i]){
				if(edge2[i][p.u]+edge2[i][p.v]+c[i]<tmp){
					tmp=edge2[i][p.u]+edge2[i][p.v]+c[i];
					flag[last]=0;
					last=i;
					if(nopay)nopay=0;
				}
				else{
					flag[i]=0;
				}
			}
			else{
				if(edge2[i][p.u]+edge2[i][p.v]<tmp){
					tmp=edge2[i][p.u]+edge2[i][p.v];
					nopay=1;
				}
			}
		}
		if(nopay==0&&last)vis[last]=1;
		p.w=tmp;
		fa[fau]=fav;
		sum+=p.w;
		cnt++;
		if(cnt==n-1)return sum;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge[i].u=u,edge[i].w=w,edge[i].v=v;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int cw;
			cin>>cw;
			edge2[i][j]=cw;
			edge2[j][i]=cw;
		}
	}
	sort(edge+1,edge+1+m,cmp);
	cout<<solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
