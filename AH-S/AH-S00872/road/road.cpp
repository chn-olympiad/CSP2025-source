#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11][10010],d[10010],u,v,w,fa[10100],f[11],fl=0;
long long ans;
struct st{
	int u,v,w;
}e;
vector<st> G,G2,G1;
bool cmp(st a,st b){
	return a.w<b.w;
}
int ufind(int x){
	while(x!=fa[x])x=fa[x];
	return x;
}
long long uni(int ci){
	G1.clear();
	long long sum=c[ci][0];
	for(int i=1;i<=ci+n;i++)fa[i]=i;
	sort(G.begin(),G.end(),cmp);
	int len=G.size();
	for(int i=0;i<len;i++){
		u=G[i].u,v=G[i].v,w=G[i].w;
		int x=ufind(u),y=ufind(v);
		if(x!=y){
			fa[x]=y;
			e.u=u,e.v=v,e.w=w;
			G1.push_back(e);
			sum+=w;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		e.u=u,e.v=v,e.w=w;
		G.push_back(e);
	}
	sort(G.begin(),G.end(),cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<m;i++){
		u=G[i].u,v=G[i].v,w=G[i].w;
		int x=ufind(u),y=ufind(v);
		if(x!=y){
			fa[x]=y;
			e.u=u,e.v=v,e.w=w;
			ans+=w;
			G2.push_back(e);
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	G.clear();
	for(int j=G2.size()-1;j>=0;j--){
		e.u=G2[j].u,e.v=G2[j].v,e.w=G2[j].w;
		G.push_back(e);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		int flag=1;
		if(c[i][0]!=0)flag=0;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0)flag=0;
		}
		if(flag==1)fl=1;
	}
	if(fl==1){
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e.u=n+i,e.v=j,e.w=c[i][j];
				G.push_back(e);
			}
			long long sum=uni(i);
			if(sum<ans){
				ans=sum;
				G.clear();
				int len=G1.size();
				for(int j=0;j<len;j++){
					e.u=G1[j].u,e.v=G1[j].v,e.w=G1[j].w;
					G.push_back(e);
				}
			}
			else f[i]=-1;
		}
		int len=G.size();
		for(int i=0;i<len;i++){
			if(G[i].u>n)f[G[i].u-n]=1;
		}
		for(int i=1;i<=k;i++){
			if(f[i]==0)ans-=c[i][0];
		}
		cout<<ans;
	}
	return 0;
}
