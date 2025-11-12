#include<bits/stdc++.h>
using namespace std;

int n,m,k;
const int N=1e6+5;
struct node{
	int to,net,w;
}a[2*N];
int h[2*N],cnt;
int p[N];
vector<int> ve[N];

void add(int u,int v,int w){
	a[cnt].to=v;
	a[cnt].w=w;
	a[cnt].net=h[u];
	h[u]=cnt++;
}

struct node2{
	int u,d;
	bool operator < (const node2 aa) const{
		return d>aa.d;
	}
};
priority_queue<node2> q;
int dis[N],vis[N]; 
bool jg[N];
void djs(int x){
	dis[x]=0;
	q.push({x,0});
	
	while(!q.empty()){
		auto s=q.top();
		q.pop();
		if(vis[s.u]==1) continue;
		vis[s.u]=1;
		
		for(int i=h[s.u];i!=-1;i=a[i].net){
			int v=a[i].to,w=a[i].w;
			if(dis[v]>dis[s.u]+w){
				dis[v]=dis[s.u]+w;
				p[v]=s.u;
				q.push({v,dis[v]});
			} 
		} 
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			ve[x].push_back(y);
		}
	}
	long long mmin=0x3f3f3f3f;
	int pos=0;
	for(int k=1;k<=n;k++){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(jg,0,sizeof(jg));
		djs(k);
		for(int i=1;i<=n;i++){
			jg[p[i]]=1;
		}
//		for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
//		cout<<endl;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(jg[i]==1) continue;
			ans+=dis[i];
//			cout<<i<<" iiiiiiiii"<<endl;
		}
//		mmin=min(mmin,ans);
		if(mmin>ans){
			mmin=ans;
			pos=k;
		}
	}
	
	cout<<mmin<<endl;
//	cout<<pos<<" pppppppp"<<endl;
	return 0;
}
