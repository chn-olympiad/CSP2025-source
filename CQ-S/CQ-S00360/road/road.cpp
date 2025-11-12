#include<bits/stdc++.h>
using namespace std;
struct point{
	int v,w,lw;
	
	bool operator<(const point b) const{
		if((lw-w)== (b.lw-b.w)){
			return w<b.w;
		}
		return (lw-w)<(b.lw-b.w);
	}
	
};
vector<vector<point> > mapp(20000);
bool f[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	if(k == 0){
		for(int i = 1;i <= m;i++) {
			int u,v,w;
			cin >> u >> v >> w;
			mapp[u].push_back({v,w,0});//在u到v之间建一条长度为w的边
			mapp[v].push_back({u,w,0});//反向建边 
		}
		priority_queue<point,vector<point>,less<point>> que;
		que.push({1,0,0});
		int ans = 0;
		while(!que.empty()){
			
			point np = que.top();
			
			que.pop();
			if(f[np.v])//已经到过这个点 
			{
				continue;
			}
			
			f[np.v] = 1;
			ans += np.w - np.lw;
			for(int i = 0;i < mapp[np.v].size();i++) {
				que.push({mapp[np.v][i].v,np.w+mapp[np.v][i].w,np.w});
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		mapp[u].push_back({v,w,0});//在u到v之间建一条长度为w的边
		mapp[v].push_back({u,w,0});//反向建边 
	}
	int c;
	
	//
	priority_queue<point,vector<point>,less<point>> que;
	for(int i = 1;i <= k;i++) {
	cin >> c;
		for(int j = 1;j <= n;j++) {
			int w;
			cin >> w;
			mapp[n+i].push_back({j,w,0});//在u到v之间建一条长度为w的边
			mapp[j].push_back({i+n,w,0});
			que.push({i+n,0,0});
		}
	}
	
	que.push({1,0,0});
	int ans = 0;
	while(!que.empty()){
			
		point np = que.top();
			
		que.pop();
		if(f[np.v])//已经到过这个点 
		{
			continue;
		}
			
		f[np.v] = 1;
		ans += np.w - np.lw;
		for(int i = 0;i < mapp[np.v].size();i++) {
			que.push({mapp[np.v][i].v,np.w+mapp[np.v][i].w,np.w});
		}
	}
	cout << ans;
		return 0;
	return 0;
} 
