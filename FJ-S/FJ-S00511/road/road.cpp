#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
const int M=1e6+5;
int n,m,k;
int as=LONG_LONG_MAX;

struct node{
	int u,v,w;
}g[M];
int c[15];
int a[15][N];
int f[N];

int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy){
		f[yy]=xx;
	}
}

bool cmp(node a,node b){
	return a.w<b.w;
}

int kruscal(){
	for(int i=1;i<=n;++i)
		f[i]=i; 
	int cnt=0,ans=0;
	sort(g+1,g+m+1,cmp);
//	cout<<"\n\n";
//	for(int i=1;i<=m;++i){
//		node r=g[i];
//		cout<<r.u<<" "<<r.v<<" "<<r.w<<"\n";
//	}
//	cout<<"\n\n";
	for(int i=1;i<=m;++i){
		int p=g[i].u,q=g[i].v;
		int xx=find(p),yy=find(q);
	
		if(xx!=yy){
			f[yy]=xx;
			++cnt;
			ans+=g[i].w;
			//cout<<p<<" "<<q<<" "<<g[i].w<<"\n";
			if(cnt==n-1)break;
		}
	}
	return ans;
}

void dfs(int cnt,int t,int s){
	if(cnt>k)return;
	as=min(as,kruscal()+s);
	//cout<<as<<"\n";
	for(int i=t+1;i<=1;++i){
		int M=m,N=n;
		++n;
		for(int j=1;j<=N;++j){
			g[++m].u=n;
			g[m].v=j;
			g[m].w=a[i][j];
		}
		dfs(cnt+1,i,s+c[i]);
		for(int j=m;j>M;--j)
			g[j].u=g[j].v=g[j].w=0;
		m=M;n=N;
	}
}

signed main(){
	
	freopen("road.in","r",stdin);
	freopen("read.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;++i){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	if(k==0){
		cout<<kruscal();
		return 0;
	}
	dfs(0,0,0);
	cout<<as;
	
	
	return 0;
}
