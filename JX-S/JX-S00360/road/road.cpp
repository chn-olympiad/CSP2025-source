//road
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
#define int long long
#define emdl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=1e4+5;
const int MAXM=1e6+5;
const int MAXK=10+3;
struct node{
	int w;
	int u,v;
};
bool cmp(node a,node b){
	return a.w<b.w;
}

int n,m,k;
node g[MAXM];

int fa[MAXN];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	return;
}
inline int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}

int ans=0;
void kk(){
	sort(g+1,g+1+m,cmp);
	
	for(int i=1;i<=m;i++){
		int u=g[i].u;
		int v=g[i].v;
		int w=g[i].w;
		int q1=find(u);
		int q2=find(v);
		if(q1==q2) continue;
		fa[q2]=q1;
		ans+=w;
	}
	return;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef LOCAL
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[i].w=w;
		g[i].u=u;
		g[i].v=v;
	}
	
	bool A=1;
	for(int i=1;i<=k;i++){
		int c_j;
		cin>>c_j;
		if(c_j!=0){
			A=0;
			break;
		}
		else{
			for(int i=1;i<=n;i++){
				int sr;
				cin>>sr;
				if(sr!=0){
					A=0;
					break;
				}
			}
			if(A==0){
				break;
			}
		}
	}
	
	if(A==1){
		cout<<"0"<<emdl;
		return 0;
	}
	
	init();
	kk();
	
	cout<<ans<<emdl;
	
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0

0
*/
