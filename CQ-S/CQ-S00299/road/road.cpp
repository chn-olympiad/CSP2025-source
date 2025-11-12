#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
const int N=1e5+10;
struct Edge{
	int to,w;
};
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f; 
}
struct Edge2{
	int from,to,w;
};
vector<Edge>edge[N];
int n,m,k;
bool cmp(Edge2 x,Edge2 y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
bitset<N+100>f;
int re=INT_MAX;
int Kruskal(vector<Edge2>edges){
	for(int i=1;i<=n+100;i++){
		fa[i]=i;
		f[i]=0;
	}
	int sum=0;
	int cnt=0;
	sort(edges.begin(),edges.end(),cmp);
	for(auto E:edges){
		int u=E.from,v=E.to,w=E.w;
		int r1=find(u),r2=find(v);
		if(r1!=r2){
			fa[r2]=r1;
			if(u<=n){
				if(!f[u])cnt++;
				f[u]=1;	
			}
			if(!f[v])cnt++;
			f[v]=1;
			sum+=w;
			if(sum>=re)return INT_MAX;
		}
		if(cnt==n){
			return sum;
		}
	}
}
int vil[11][N];
bool _A=1;
int c[11];
void print(){
	cout<<"OK\n";
}vector<Edge2>edges;

void solve1(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			edges.pb({i+n,j,vil[i][j]});
		}
	}
	cout<<Kruskal(edges);
	exit(0);
}
void solve2(){
	vector<int>tem;
	vector<Edge2>t=edges;
	re=Kruskal(t);
	for(int s=0;s<(1<<k);s++){
		int sum=0;
		for(int i=0;i<k;i++){
			if((s>>i)&1){
				tem.push_back(i+1);
				sum+=c[i+1];
			}
		}
		while(t.back().from>n){
			t.erase(t.end()-1,t.end());
		}
		for(auto E:tem){
			for(int i=1;i<=n;i++){
				t.push_back({E+n,i,vil[E][i]});
			}
		}
		re=min(re,Kruskal(t)+sum);
	}
	cout<<re;
	exit(0);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){	
		int x=read(),y=read(),z=read();
		edge[x].pb({y,z});
		edge[y].pb({x,z});
		edges.pb({x,y,z});
	}
	if(k==0){
		cout<<Kruskal(edges);	
		exit(0);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])_A=0; 
		for(int j=1;j<=n;j++){
			cin>>vil[i][j];
		}
	}
	if(_A)solve1();
	solve2();
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
