#include<bits/stdc++.h>
#define int long long 
#define fast int 

using namespace std;

const int N=1e5+100;

int n,m,k,cnt=0,fa[N];

int a[20][N],c[20];

int head[N];

struct node{
	int nex,to,w;
}edge[N];

struct Node{
	int u,v,w;
}e[N];

void add(int u,int v,int w){
	edge[++cnt].to=head[u];
	edge[cnt].nex=v;
	edge[cnt].w=w;
	head[u]=cnt;
}

bool cmp(Node a,Node b){
	return a.w<b.w;
}

int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>k;
	
	if (k==0){
		int ans=0,ccnt=0;
		for (fast i=1;i<=n;i++) fa[i]=i;
		for (fast i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1,e+m+1,cmp);
		for (fast i=1;i<=m;i++){
			int fu=find(e[i].u);
			int fv=find(e[i].v);
			
			if (fu!=fv){
				fa[fu]=fv;
				ccnt++;
				ans+=e[i].w;
				if (ccnt>=n-1){
					break;
				}
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	
	for (fast i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	
	for (fast i=1;i<=k;i++){
		cin>>c[i];
		for (fast j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4


有点感觉了

but 有点少
*/