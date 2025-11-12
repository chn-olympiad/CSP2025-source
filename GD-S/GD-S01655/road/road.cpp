#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
struct po{
	int v,w;	
};
vector<po>e[N];
int a[10004][10004];//u v之间关系 
int b[N];//u有几个孩子 
int son[N][N];//这些孩子是谁 
vector<int>d(N+10,INT_MAX);//答案 
int n,m,k;
ll ans;
int c[N];
int bc[N];
int pp[10004][10004];//判断是否买过 
int pre[N];//前驱 
void zdl(int s){
	d[s]=0;
	queue<int>q;
	vector<int>vis(N+10,0);
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=1;i<=b[u];i++){
			int v,w;
			v=son[u][i];//孩子
			w=a[u][v];//路径权值 
			if(d[v]>d[u]+w){
				pre[v]=u;
				d[v]=d[u]+w;
				if(vis[v]==0){
					q.push(v);
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		b[u]++;
		b[v]++;
		son[u][b[u]]=v;
		son[v][b[v]]=u;
	}	
	for(int i=n+1;i<=n+k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w,v,u;
			v=j;
			u=i;
			cin>>w; 
		}
	}
	zdl(1);
	for(int i=2;i<=n;i++){
		int u=i;
		
		while(u!=0){
			int dad=0;
			dad=pre[u];
			
			if(pp[dad][u]==0||pp[u][dad]==0){
				
				ans+=a[dad][u];
				if(dad>n){
					bc[dad]=1;
				}
				else if(u>n){
					bc[u]=1;
				}
//				cout<<ans<<" ";
				pp[dad][u]=1;
				pp[u][dad]=1;
			}
//			cout<<u<<" ";
			u=dad;
		}
//		cout<<endl;
	}
	cout<<ans;
	return 0;
}

