//原本连边
//乡镇改造后两两连边（2^n暴力枚举） 
//kruskal 
#include <bits/stdc++.h>
#define int long long
using namespace std;
map<pair<int,int>,int> e;
map<pair<int,int>,int> g;
map<pair<int,int>,bool> flag;
int c[15],a[15][10005];
bool f[15];
int ans=1e18;
int n,m,k;
void dfs(int depth,int k){
	if(depth<k){
		dfs(depth+1,k);
		f[depth+1]=1;
		dfs(depth+1,k);
		f[depth+1]=0;
	}
	else{
//		cout << '*';
		int ans1=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=k;l++){
					if(!f[l]||i==j)continue;
					e[{i,j}]=min(e[{i,j}],a[l][i]+a[l][j]);
					if(!flag[{i,j}])e[{i,j}]=a[l][i]+a[l][j];
				}
			}
		}
		bool fql=false;
		for(int i=1;i<=k;i++){
			if(f[i])ans1+=c[i],fql=true;
		}
		priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				q.push({e[{i,j}],{i,j}});
			}
		}
		int cnt=0;
		map<pair<int,int>,bool> mp;
		while(q.size()){
			if(cnt==n-1)break;
			pair<int,pair<int,int> > now=q.top();
			q.pop();
			if(!mp[now.second]&&now.second.first!=now.second.second&&(fql==true||flag[{now.second}]==true)){
				cnt++;
				ans1+=now.first;
				mp[now.second]=mp[{now.second.second,now.second.first}]=true;
//				cout << now.first << ' ' << now.second.first << ' ' << now.second.second << '\n';
			}
		}
		ans=min(ans1,ans);
		e=g;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		e[{u,v}]=e[{v,u}]=w;
		g[{u,v}]=g[{v,u}]=w;
		q1.push({w,{u,v}});
		q1.push({w,{v,u}});
		flag[{u,v}]=flag[{v,u}]=true;
	}
	if(k==0){
		int cnt=0;
		map<pair<int,int>,bool> mp;
		while(q1.size()){
			if(cnt==n-1)break;
			pair<int,pair<int,int> > now=q1.top();
			q1.pop();
			if(!mp[now.second]&&now.second.first!=now.second.second){
				cnt++;
				ans+=now.first;
				mp[now.second]=mp[{now.second.second,now.second.first}]=true;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	dfs(0,k);
	cout << ans;
	return 0;
}
