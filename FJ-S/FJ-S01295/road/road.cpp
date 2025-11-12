#include<bits/stdc++.h>
#define int long long
using namespace std;
int vis[20];
int n,m,k;
struct node{
	int u,v,w,flag,vis;
	friend bool operator <(node a,node b){
		return a.w>b.w;
	}
};
priority_queue<node> q;
int fa[10040],flg[20];
unordered_map<int,int> mp;
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
} 
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	fa[y]=x;
}
int kruskal(){
	int ans=0;
	int cnt=0;
	while(cnt<n-1){
		node x=q.top();
		q.pop();
		if(find(x.u)==find(x.v))continue;
		else{
//			cout<<x.u<<" "<<x.v<<" "<<x.w<<" "<<x.flag<<" "<<x.vis<<"\n";
//			if(x.vis)vis[x.flag]=1;
			if(!x.flag)ans+=x.w;
			else {
				if(!vis[x.flag]&&x.vis)ans+=x.w,vis[x.flag]=1;
				else if(vis[x.flag])ans+=x.w-mp[x.flag];
				else {
					x.w+=mp[x.flag];
					x.vis=1;
					q.push(x);
					continue;
				}
			}
			cnt++;
			merge(x.u,x.v); 
		}
//		cout<<ans<<"a/a/\n";
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(n+k+10);
	node t;
	t.flag=t.vis=0;
	for(int i=1;i<=m;i++){
		cin>>t.u>>t.v>>t.w;
		t.flag=0;
		q.push(t);
	}
	if(k==0){cout<<kruskal()<<"\n";return 0;}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		mp[i]=c;
		vector<int> v(n+1);
		for(int j=1;j<=n;j++)cin>>v[j];
		for(int j=1;j<n;j++)
			for(int k=j+1;k<=n;k++){
				t.u=j,t.v=k,t.w=v[j]+v[k],t.flag=i,t.vis=0;
				q.push(t);
//				cout<<t.u<<" "<<t.v<<" "<<v[j]<<"\n";
//				mmp[{j,k}]=mmp[{k,j}]=v[j]+v[k];
			}
//		for(int j=1;j<=n;j++){
//			cin>>t.w;
//			t.u=n+i,t.v=j;
//			t.flag=n+i;
//			q.push(t);
//		}
	}
	cout<<kruskal()<<"\n";
}
