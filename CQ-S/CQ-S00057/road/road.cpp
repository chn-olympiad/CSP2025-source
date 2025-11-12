#include<bits/stdc++.h>
using namespace std;
namespace code{
	#define maxn 100005
	int n,m,k,c[maxn*10],fa[100005],cnt=0,sum=0;
	bool vist[maxn*10],lvist[maxn*10];
	struct node{
		int y,z;
	};
	struct node2{
		int x,y,z;
		bool operator <(const node2& a)const{
			return a.z>z;
		}
	}b[maxn*10];
	vector<node>g[maxn*10];
	int getfa(int u){
		if(fa[u]==u) return u;
		return fa[u]=getfa(fa[u]);
	}
	void mst(){
		for(int i=1;i<=cnt;i++){
			fa[i]=i;
		}
		int now=0;
		sort(b+1,b+cnt+1);
		for(int i=1;i<=cnt;i++){
			int x=b[i].x,y=b[i].y;
			int fax=getfa(x),fay=getfa(y);
//			cout<<x<<" "<<fax<<" "<<y<<" "<<fay<<'\n';
			if(fax!=fay){
//				cout<<i<<" "<<b[i].z<<" "<<now<<'\n';
				g[x].push_back({y,b[i].z});
				g[y].push_back({x,b[i].z});
				fa[fax]=fay;
				sum+=b[i].z;
				now++;
				if(now==n+k-1) 
					break;
			}
		}
	}
	bool dfs(int u){
		if(g[u].size()==0) return true;
		for(int i=0;i<g[u].size();i++){
			node nex=g[u][i];
			if(g[u][i].y>n && vist[nex.y]==false){
				lvist[nex.y]=true;
				vist[nex.y]=true;
				if(dfs(nex.y)==false) lvist[nex.y]=false;
			}
		}
		return false;
	}
	void dfs2(int u){
		for(int i=0;i<g[u].size();i++){
			node nex=g[u][i];
			if(lvist[nex.y]==true && vist[nex.y]==false){
				vist[nex.y]=true;
				sum-=nex.z;
				sum-=c[nex.y]; 
				dfs2(nex.y);
			}
		}
	}
	signed main(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			b[i].x=x,b[i].y=y,b[i].z=z;
		}
		cnt=m;
		for(int i=1;i<=k;i++){
			cin>>c[n+i];
			for(int j=1;j<=n;j++){
				int z;
				cin>>z;
				cnt++;
				b[cnt].x=n+i,b[cnt].y=j,b[cnt].z=z;
			}
		}
		mst();
		if(k==0){
			cout<<sum;
			return 0;
		}else{
//			cout<<sum<<"-----"<<'\n';
			for(int i=n;i<=n+k;i++){
				if(vist[i]==false){
					vist[i]=true;
					dfs(i);
				}
			}
			memset(vist,0,sizeof(vist));
			for(int i=n;i<=n+k;i++){
				if(lvist[i]==true){
					sum-=c[i];
					vist[i]=false;
					dfs2(i);
				}
			}
			cout<<sum;
		}
		return 0;
	}
}signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return code::main();
}
/*
48
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
