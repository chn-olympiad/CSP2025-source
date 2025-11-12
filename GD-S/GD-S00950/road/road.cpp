#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+10,inf=1e15;

int n,m,k;

int road[11][maxn],r[maxn][maxn];

int siz[maxn],fa[maxn];
vector<int> ch[maxn];

int find(int x){
	return (x==fa[x])?x:find(fa[x]);
}

void merge(int x,int y){
	x=find(x),y=find(y);
	if(siz[x]<siz[y])swap(x,y);
	siz[x]+=siz[y];
	fa[y]=x;
	ch[x].push_back(y);
}

int add(int x,int y){
	x=find(x),y=find(y);
	vector<int> a,b;
	queue<int> p;
//	cout<<"f"<<endl;
	p.push(x);
	a.push_back(x);
	while(!p.empty()){
		int t=p.front();
		p.pop();
		for(auto v:ch[t]){
			p.push(v);
			a.push_back(v);
		}
	}
//	assert(a.size()==siz[x]);
//	cout<<"s"<<endl;
	p.push(y);
	b.push_back(y);
	while(!p.empty()){
		int t=p.front();
		p.pop();
		for(auto v:ch[t]){
			p.push(v);
			b.push_back(v);
		}
	}
//	cout<<b.size()<<" "<<siz[y]<<" "<<y<<endl;
//	assert(b.size()==siz[y]);
//	cout<<"complete"<<endl;
	int ans=inf;
	for(int i:a){
		for(int j:b){
			ans=min(ans,r[i][j]);
		}
	}
	return ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		r[u][v]=r[v][u]=w;
	}
//	cout<<"f"<<endl;
	for(int j=1;j<=k;j++)
	for(int i=0;i<=n;i++)cin >> road[j][i];
//	cout<<"s"<<endl;	
	for(int i=1;i<=n;i++){
//		r[i][0]=inf;
		for(int j=1;j<=n;j++){
//			cout<<"t"<<endl;
			if(r[i][j]==0)r[i][j]=inf;
//			cout<<"ff"<<endl;
			for(int l=1;l<=k;l++){
				if(i==j)continue; 
				r[i][j]=min(r[i][j],road[l][i]+road[l][j]+road[l][0]);
//				cout<<l<<endl;
			}
//			assert(k==0||r[i][j]!=inf);
//			cout<<r[i][j]<<" ";
		}
//		cout<<endl;
	}

	int ans=0;
	for(int i=1;i<=n;i++){
		int inc=0,to=0;
		for(int j=1;j<=n;j++){
			if(find(i)==find(j))continue;
			int t=add(i,j);
			if(inc==0||t<inc)inc=t,to=j;
		}
		if(to==0)continue;
		ans+=inc;
		merge(i,to);
//		cout<<i<<" "<<to<<" "<<ans<<endl;
	}
//	assert(siz[find(1)]==n);
	cout<<ans<<endl;
	return 0;
}
