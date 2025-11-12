#include<bits/stdc++.h>
using namespace std;

//50pt dinic

const int MN=1e5+1e5;
const int INF=0x3f3f3f3f;
int T,n,s,t,dis[MN],vis[MN],cur[MN];
long long anss;
struct Dat{
	int a,b,c;
}a[MN];
struct Node{int y,k,id,cost;};
vector<Node> v[MN];

bool cmp(Dat n1,Dat n2){
	if(n1.a==n2.a) return n1.b<n2.b;
	else return n1.a>n2.a;
}

void add(int a,int b,int k,int cost){
	int sza=v[a].size(),szb=v[b].size();
	v[a].push_back({b,k,szb,cost});
	v[b].push_back({a,0,sza,-cost});
}

bool spfa(int s){
	fill(dis,dis+n+10,-INF);
	queue<int> q;
	q.push(s);
	dis[s]=0;
	vis[s]=true;

	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=false;

		for(int i=0;i<v[x].size();i++){
			int y=v[x][i].y;
			int k=v[x][i].k;
			int cost=v[x][i].cost;

			if(dis[y]<dis[x]+cost && k){
				dis[y]=dis[x]+cost;

				if(!vis[y]){
					q.push(y);
					vis[y]=true;
				}
			}
		}
	}
	memset(cur,0,sizeof(cur));
	return dis[t]!=-INF;
}

int dfs(int x,int ans){
	if(x==t) return ans;
	if(vis[x]) return 0;

	vis[x]=true;
	
	for(int &i=cur[x];i<v[x].size();i++){
		int y=v[x][i].y;
		int k=v[x][i].k;
		int id=v[x][i].id;
		int cost=v[x][i].cost;

		if(!vis[y] && k && dis[y]==dis[x]+cost){
			int tmp=dfs(y,min(ans,k));
			if(tmp){
				v[x][i].k-=tmp;
				v[y][id].k+=tmp;
				anss+=cost*tmp;
				vis[x]=false;
				return tmp;
			}else dis[y]=-INF;
		}
	}
	vis[x]=false;
	return 0;
}

int dinic(){
	int tmp,ans=0;
	while(spfa(s)) while(tmp=dfs(s,INF)) ans+=tmp;
	return ans;
}

void subtask1(){
	anss=0;
	for(int i=0;i<=n+10;i++) v[i].clear();

	s=0,t=n+5;

	add(n+1,t,n/2,0);
	add(n+2,t,n/2,0);
	add(n+3,t,n/2,0);

	for(int i=1;i<=n;i++){
		add(s,i,1,0);
		add(i,n+1,1,a[i].a);
		add(i,n+2,1,a[i].b);
		add(i,n+3,1,a[i].c);
	}
	
	dinic();

	cout<<anss<<"\n";
}

void subtaskB(){
	sort(a+1,a+n+1,cmp);
	long long tmp=0;
	for(int i=1;i<=n/2;i++) tmp+=a[i].a;
	for(int i=n/2+1;i<=n;i++) tmp+=a[i].b;
	cout<<tmp<<"\n";
}


void work(){
	cin>>n;

	bool speB=1;

	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].c!=0) speB=0;
	}
	
//	if(speB) subtaskB();
//	else subtask1();
	subtask1();
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>T;

	while(T--) work();

	return 0;
}
