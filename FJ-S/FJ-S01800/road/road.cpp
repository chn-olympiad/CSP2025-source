#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+55;
const int M=4e6+5;
const int K=15;
int n,m,k,cnt,ans,Ans=1e18,flag=1;
struct node{
	int u,v,w;
}e[M],t[M];
int c[K],a[K][N];
int fa[N];
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
inline void add(int u,int v,int w){
	cnt++;
	e[cnt].u=u,e[cnt].v=v,e[cnt].w=w;
	t[cnt].u=u,t[cnt].v=v,t[cnt].w=w;
}
bool cmp(node x,node y){
	return x.w<y.w; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)
			flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)
				flag=0;
		}
	} 
	if(k>5||flag){
		cout<<0;
		return 0;
	}
	for(int st=0;st<(1<<k);st++){
		ans=0;
		int mm=n;
		cnt=2*m;
		for(int i=1;i<=n+k;i++)
			fa[i]=i; 
		for(int i=1;i<=cnt;i++){
			e[i].u=t[i].u;
			e[i].v=t[i].v;
			e[i].w=t[i].w;
		}
		for(int i=1;i<=k;i++)
			if((st>>(i-1))&1){
				mm++;
				ans+=c[i];
				for(int j=1;j<=n;j++){
					add(n+i,j,a[i][j]);
					add(j,n+i,a[i][j]);
				}
			} 
		sort(e+1,e+1+cnt,cmp);
		for(int i=1;mm>0&&i<=cnt;i++){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy)
				continue;
			fa[fx]=fy;
			mm--;
			ans+=e[i].w;
		}
		//cout<<st<<'\n'; 
		Ans=min(Ans,ans); 
	}
	cout<<Ans;
	return 0;
}

