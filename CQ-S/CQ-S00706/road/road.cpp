#include<bits/stdc++.h>
using namespace std;
#define int long long
//ÄÜÄÃ56·ÖÂğ£¬ÄÜÂğ£¿ 
int fa[10025],c[105],p[105][10005],n,m,k,flag[11005],minn=1e18;
struct node{
	int u,v,w;
};
bool cmp(node x,node y){return x.w<y.w;}
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
} 
vector<node>q;
void dfs(int x){
	if(x>k){
		int ans=0,num=0,kk=0;
		vector<node> v;
		for(int i=1;i<=k;i++){
			if(flag[i]){
				ans+=c[i];
				kk++;
				for(int j=1;j<=n;j++) v.push_back({n+i,j,p[i][j]});
			}
		}
		for(int i=0;i<(int)q.size();i++)v.push_back(q[i]);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<(int)v.size();i++){
			if(num>=n+kk) break;
			int xx=find(v[i].u),yy=find(v[i].v);
			if(xx!=yy)fa[xx]=yy,num++,ans+=v[i].w;
		}
		minn=min(minn,ans);
		return;
	}
	flag[x]=1;
	dfs(x+1);
	flag[x]=0;
	dfs(x+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v1,w;
		cin>>u>>v1>>w;
		if(u>v1) swap(u,v1);
		q.push_back({u,v1,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>p[i][j];
	}
	if(m<=1e5){
		dfs(1);
		cout<<minn;
	}
	else{
		for(int i=1;i<=k;i++) flag[i]=1;
		int ans=0,num=0;
		vector<node> v;
		for(int i=1;i<=k;i++){
			if(flag[i]){
				ans+=c[i];
				for(int j=1;j<=n;j++) v.push_back({n+i,j,p[i][j]});
			}
		}
		for(int i=0;i<(int)q.size();i++)v.push_back(q[i]);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(v.begin(),v.end(),cmp);
		for(int i=0;i<(int)v.size();i++){
			if(num>=n+k) break;
			int xx=find(v[i].u),yy=find(v[i].v);
			if(xx!=yy)fa[xx]=yy,num++,ans+=v[i].w;
		}
		cout<<ans;
	} 
}

