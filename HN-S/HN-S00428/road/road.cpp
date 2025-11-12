#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

int f[N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int n,m,k;

struct node{
	int u,v,w;
}road[N];

queue<node>q[20];
int a[15],vis[15];
bool cmp(node a,node b){
	return a.w<b.w;
}
int ans=0;
map<int,int>num;
void dfs(){
	
	
	while(true){
		int cnt=1e9;
		int idx;
		for(int i=0;i<=k;i++){
			int sum=q[i].front().w;
			if(vis[i])sum-=a[i];
			if(cnt>sum){
				cnt=sum;
				idx=i;
			}
		}
		
		int u=q[idx].front().u;
		int v=q[idx].front().v;
		q[idx].pop();
		if(find(u)!=find(v)){
			ans+=cnt;
			vis[idx]=1;
			f[find(u)]=find(v);
			
			if(u<=n)num[u]=1;
			if(v<=n)num[v]=1;
			if(num.size()==n)break;
		
		}
	}
}
node road1[N];
node road2[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+1+k;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		road[i]={x,y,z};
		road1[i]={x,y,z};
	}
	sort(road+1,road+m+1,cmp);
	for(int i=1;i<=m;i++){
		q[0].push(road[i]);
	}
	for(int i=1;i<=k;i++){
		
		int x,y,z;
		cin>>a[i];
		for(int j=1;j<=m;j++){
			cin>>z;
			road2[j]={i+n,j,z+a[i]};
		}
		sort(road2+1,road2+m+1,cmp);
		for(int j=1;j<=m;j++){
			q[i].push(road2[j]);
		}
	}
	dfs();
	cout<<ans;
	return 0;
}
