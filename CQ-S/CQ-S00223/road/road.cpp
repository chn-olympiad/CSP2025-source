#include<cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
int n,m,k,id,a[18][10005],c[18],t[18],x,l[18];
long long an,cn;
struct node{
	int u,v,w;
}e[1000005],f[18][10005];
struct dsu{
	int fa[12005],s[12005];
	int find(int x){
		if(x==fa[x])return x;
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx==fy)return;
		if(s[fx]<s[fy])fa[fx]=fy,s[fy]+=s[fx];
		else fa[fy]=fx,s[fx]+=s[fy];
	}
}t1;
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  std::ios::sync_with_stdio(0);
  std::cin.tie(0),std::cout.tie(0);
	std::cin>>n>>m>>k;
	for(int i=1;i<=n;i=-(~i))t1.fa[i]=i,t1.s[i]=1;
	for(int i=1;i<=m;i=-(~i)){
	std::cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i=-(~i)){
		std::cin>>c[i];
		for(int j=1;j<=n;j++){
			std::cin>>f[i][j].w;
			f[i][j].u=i+n;
			f[i][j].v=j;
		}
		std::sort(f[i]+1,f[i]+n+1,cmp);
	}
	std::sort(e+1,e+m+1,cmp);
	id=1;
	for(int i=1;i<=m;i=-(~i)){
		int fx=t1.find(e[i].u),fy=t1.find(e[i].v);
		if(fx!=fy){
			an+=e[i].w;
			t1.merge(fx,fy);
			++id;
			f[k+1][id]=e[i];
		}
	}
	int fx,fy;
	for(int S=1;S<(1<<k);S=-(~S)){
		x=1;
		t[1]=k+1;
		cn=0;
		for(int i=1;i<=n+k;i=-(~i))t1.fa[i]=i,t1.s[i]=1;
		l[k+1]=2;
		for(int j=1;j<=k;j=-(~j)){
			l[j]=1;
			if(S&(1<<(j-1))){
				x++;
				t[x]=j;
				cn+=c[j];
			}
		}
		int cnt=0;
		while(cnt<n+x-2){
			int j=0;
			for(int i=1;i<=x;i=-(~i)){
				while(l[t[i]]<=n){
					fx=t1.find(f[t[i]][l[t[i]]].u),fy=t1.find(f[t[i]][l[t[i]]].v);
					if(fx!=fy)break;
					l[t[i]]=-(~l[t[i]]);
				}
				if(l[t[i]]>n)continue;
				if(j==0||f[t[i]][l[t[i]]].w<f[j][l[j]].w)j=t[i];
			}
			cnt=-(~cnt);
			cn+=f[j][l[j]].w;
			if(cn>=an)break;
			t1.merge(f[j][l[j]].u,f[j][l[j]].v);
			l[j]=-(~l[j]);
		}
		if(an>cn)an=cn;
	}
	std::cout<<an;
	return 0;
}
