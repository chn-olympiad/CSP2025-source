#include <bits/stdc++.h>
#define int long long
#include <cstdio>
using namespace std;
int n,m,k;
int ans=2e14;
int num=0;
int fir[200005];
struct edge{
	int fro;
	int nex;
	int to;
	int w;
	int id;
	bool operator < (const edge &x)const{
		return w<x.w ;
	}
}e[4000005];
int sum=0;
int fa[200005];
inline find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool flag=1;
inline void bui(int a,int b,int c){
	num++;
	e[num].fro =a;
	e[num].nex =fir[a];
	fir[a]=num;
	e[num].to =b;
	e[num].w =c;
	e[num].id =num;
	return ;
}
inline bool cmp(edge a,edge b){
	return a.id <b.id ;
}
inline void sol(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int p=n+k-1,q=0;
	sort(e+1,e+num+1);
	for(int i=1;i<=num;i++){
		if(sum>ans) return ;
		if(q==p && flag){
			ans=sum;
			return ;
		}
		if(find(e[i].fro )==find(e[i].to )) continue;
		sum+=e[i].w ;
		fa[find(e[i].fro )]=find(e[i].to );
		q++;
	}
	if(flag==0) sort(e+1,e+num+1,cmp);
	ans=min(ans,sum);
	return ;
}
int w[15][20005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		bui(u,v,c);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>w[i][j];
		}
		if(w[i][0]) flag=0;
	}
	if(flag){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				bui(n+i,j,w[i][j]);
			}
		}
		sol();
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		int tmpnum=num;
		sum=0;
		for(int j=1;j<=k;j++){
			if(((i>>(j-1))&1)){
				sum+=w[j][0]+w[j][j];
				for(int g=1;g<=n;g++){
					if(j!=g){
						bui(j,g,w[j][g]);
					}
				}
			}
		}
		sol();
		num=tmpnum;
	}
	cout<<ans<<'\n';
	return 0;
}
//[32,40]
