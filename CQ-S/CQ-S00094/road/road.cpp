#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline void read(int &x){
	x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
}
const int maxm=1e6+5;
const int maxn=1e4+55;
int n,m,k;
int fa[maxn];
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct edge{
	int x,y,w;
}e[maxm];
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
int c[15],a[15][maxn],id[15][maxn];
int CZC;
inline bool cmp2(int x,int y){
	return a[CZC][x]<a[CZC][y];
}
int tot[11];
const int INF=1e9+1;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(e[i].x),read(e[i].y),read(e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	ll ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	int tt=0;
	for(int i=1;i<=m;i++){
		int rx=find(e[i].x),ry=find(e[i].y);
		if(rx==ry) continue; 
		fa[rx]=ry;
		e[++tt]=e[i];
		ans+=(ll)e[i].w;
	}
	m=tt;
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			id[i][j]=j;
			read(a[i][j]);
		}
		CZC=i;
		sort(id[i]+1,id[i]+n+1,cmp2);
	}
	for(int s=1;s<(1<<k);s++){
		ll sum=0;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		vector<int> zj;
		for(int i=0;i<k;i++){
			if((s>>i)&1){
				sum+=c[i+1];
				zj.push_back(i+1); 
			}
		}
		memset(tot,0,sizeof(tot));
		if(sum>ans) continue;
		int kk=(int)zj.size();
		for(int cnt=1;cnt<n+kk;cnt++){
			while(tot[0]<m && find(e[tot[0]+1].x)==find(e[tot[0]+1].y)) tot[0]++;
			int mn=INF,mnto=0;
			if(tot[0]<m) mn=e[tot[0]+1].w;
			for(auto x:zj){
				while(tot[x]<n && find(x+n)==find(id[x][tot[x]+1])) tot[x]++;
				if(tot[x]<n && a[x][id[x][tot[x]+1]]<mn){
					mnto=x;
					mn=a[x][id[x][tot[x]+1]];
				}
			}
			sum+=(ll)mn;
			if(sum>ans) break;
			if(mnto==0){
				fa[find(e[tot[0]+1].x)]=find(e[tot[0]+1].y);
				tot[0]++;
			}
			else{
				fa[find(n+mnto)]=find(id[mnto][tot[mnto]+1]);
				tot[mnto]++;
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
/*
�����һ��1e8���ҵĸ��Ӷ�Ӧ�����ܹ��İɡ� 
*/
