#include<bits/stdc++.h>
using namespace std;

const int N=1.2e6+6;
const int M=1e4+4;
bool b[M];
int n,m,k,fa[N],cnt;
long long ans;
struct node{
	int u,v;long long w;
	bool f=0;
	long long xx;
	bool operator<(const node& x){
		return w<x.w;
	}
}e[N];

int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>e[cnt].u>>e[cnt].v>>e[cnt].w;
		e[cnt].xx=0;
	}
	for(int i=1;i<=k;i++){
		int x;cin>>x;
		for(int j=1;j<=n;j++){
			e[++cnt].u=n+i;
			e[cnt].v=j;
			int y;cin>>y;
			e[cnt].w=x+y;
			e[cnt].xx=x;
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+cnt+1);
//	for(int i=1;i<=cnt;i++){
//		cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
//	}
	int sum=0;
	for(int i=1;i<=cnt;i++){
		int x=e[i].u;
		int y=e[i].v;
		int r1=find(e[i].u);
		int r2=find(e[i].v);
		if(r1!=r2){
			fa[r1]=r2;
			ans+=e[i].w;
			if(x>n&&b[x]==1){
				ans-=e[i].xx;
			}
			b[x]=1;
			b[y]=1;
		}
		bool flag=0;
		for(int j=1;j<=n;j++) if(b[j]==0) flag=1;
		if(!flag) break;
	}
	cout<<ans;
	return 0;
}

