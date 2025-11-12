#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int const D=1e4+100;
int dis[D][D];
int c[100];
int a[100][D];
struct Node{
	int to;
	int w;
};
vector<Node>s[D];
bool use[D];
long long ans=0;
struct node{
	int to;
	int num;
	bool operator <(const node&p)const{
		return num>p.num;
	}
};
priority_queue<node>ss;
bool visited[D];
int sum=0;
void prim(int x){
	visited[x]=true;
	sum++;
	for(int i=0;i<s[x].size();i++){
		if(s[x][i].to>n){
			if(use[s[x][i].to-n]==false){
				ss.push(node{s[x][i].to,s[x][i].w+c[s[x][i].to-n]});
				use[s[x][i].to]=true;
			}
			else{
				ss.push(node{s[x][i].to,s[x][i].w});
			}
		}
		else{
			ss.push(node{s[x][i].to,s[x][i].w});
		}
	}
	while(!ss.empty()){
		if(sum==n)break;
		int v=ss.top().to,ww=ss.top().num;
		ss.pop();
		if(visited[v])continue;
		visited[v]=true;
		if(v<=n){
			sum++;
		}
//		cout<<sum<<endl;
//		cout<<v<<' '<<ww<<endl;
		ans+=ww;
		for(int i=0;i<s[v].size();i++){
			if(visited[s[v][i].to])continue;
			if(s[v][i].to>n){
				if(use[s[v][i].to-n]==false){
					ss.push(node{s[v][i].to,s[v][i].w+c[s[v][i].to-n]});
					use[s[v][i].to]=true;
				}
				else{
					ss.push(node{s[v][i].to,s[v][i].w});
				}
			}
			else{
				ss.push(node{s[v][i].to,s[v][i].w});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		s[u].push_back(Node{v,w});
		s[v].push_back(Node{u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			s[i+n].push_back(Node{j,a[i][j]});
			s[j].push_back(Node{i+n,a[i][j]});
		}
	}
	prim(1);
	cout<<ans;
	return 0;
}
