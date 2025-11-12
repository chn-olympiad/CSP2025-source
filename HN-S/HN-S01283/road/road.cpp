#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e4+20;
int n,m,k;
LL we[23][N],spend[23],cost[23];
int S[N],fa[N];
int vis[23];
struct node{
	int x,y,type;
	LL z; 
};
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
void merge(int a,int b){//aÎªÀÏ´ó 
	a=get(a),b=get(b);
	if(a==b) return ;
	fa[b]=a;
	S[a]+=S[b]; 
}
bool operator <(const node &a,const node &b){
	if(a.z!=b.z)return a.z<b.z;
	return a.type<b.type;
}
bool operator >(const node &a,const node &b){
	if(a.z!=b.z)return a.z>b.z;
	return a.type>b.type;
}
priority_queue<node,vector<node>,greater<node> > g,g1;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		if(i<=n) S[i]=1;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		LL z;
		cin>>x>>y>>z;
		g.push(node{x,y,0,z});
	}
	for(int i=1;i<=k;i++){
		LL w; 
		cin>>w;
		cost[i]=w;
		for(int j=1;j<=n;j++){
			LL p;
			cin>>p;
			we[i][j]=p;
			g.push(node{j,n+i,i,p+w});
		}
	}
	g1=g;
	LL ans=0;
	while(1){
		node now=g.top();
		g.pop();
		
		if(get(now.x)==get(now.y)) continue;
	//	cout<<now.x<<" "<<now.y<<" "<<now.type<<" "<<now.z<<" "<<vis[now.type]<<endl; 
		merge(now.x,now.y);
		ans+=now.z;
		if(now.type){
			if(!vis[now.type]){
				for(int i=1;i<=n;i++) g.push(node{i,n+now.type,now.type,we[now.type][i]});
			}
			vis[now.type]++;
			spend[now.type]=now.z;
		}
		if(S[get(1)]==n){
		//	cout<<ans<<endl; 
			for(int i=1;i<=k;i++){
				if(vis[i]==1){
				//	cout<<spend[i]<<endl;
					ans-=spend[i];
				}
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
