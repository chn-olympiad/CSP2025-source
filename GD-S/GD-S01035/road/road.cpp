#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e4+20;
int n,m,d,x,y,z,o,fa[N],a[N][15],ans,num,to=INF;
bool pan;
struct node{
	int u,v,w;
	node(){
	}
	node(int u1,int v1,int w1){
		u=u1;
		v=v1;
		w=w1;
	}
	bool operator > (const node p) const {
		return p.w<w;
	}
};
int fd(int x){
	if(fa[x]==x){
		return x;
	}
	return fd(fa[x]);
}
priority_queue<node,vector<node>,greater<node> >p;
vector<node>G;
void make(){
	int l=G.size();
	for(int i=0;i<l;++i){
		p.push(G[i]);
	}
}
void add(int u,int v,int w){
	G.push_back(node(u,v,w));
	p.push(node(u,v,w));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>d;
	for(int i=1;i<=m;++i){
		cin>>x>>y>>z;
		add(x,y,z);
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	while(!p.empty()){
		node q=p.top();
//		cout<<q.w<<endl;
		p.pop();
		int x=fd(q.u),y=fd(q.v);
		if(x!=y){
			num+=q.w;
			fa[x]=y;
		}
	}
	for(int i=1;i<=n+d;++i){
		fa[i]=i;
	}
	for(int i=1;i<=d;++i){
		cin>>o;
		to=min(o,to);
		for(int j=1;j<=n;++j){
			cin>>x;
			G.push_back(node(i+n,j,x));
//			add(i+n,j,x);
		}
	}
	make();
	while(!p.empty()){
		node q=p.top();
		p.pop();
		int x=fd(q.u),y=fd(q.v);
		if(x!=y){
			ans+=q.w;
			fa[x]=y;
		}
	}
//	cout<<ans+to<<" "<<num<<endl;
	cout<<min(ans+to,num)<<endl;
	return 0;
}
