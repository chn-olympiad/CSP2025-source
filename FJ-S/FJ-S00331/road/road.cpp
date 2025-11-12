#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;
const int M=1e6;
struct ct{
	int next,to,w; 
}edge[2*M+5];

int f[N],head[N],cnt=0;
void add(int u,int v,int w){
	cnt++;
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].w=w;
	head[u]=cnt;
}
long long dis[M],vis[N];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(ct a,ct b){
	return a.w <b.w ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans=0;
	int n,m,k,u,v,w,c;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
    }
    for(int i=1;i<=k;i++){
       for(int j=1;j<=n+1;j++){
       	cin>>c;
	   }
	}
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=n-1;i++){
    	ans+=edge[i].w;
	}
	cout<<ans;
	return 0;
}