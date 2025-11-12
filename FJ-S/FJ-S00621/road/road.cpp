#include<bits/stdc++.h>
using namespace std;
#define int long long
#define node pair<pair<int,int>,int>
#define sum first.first
#define to first.second
#define id second
const int N=1e6+15;
vector<pair<int,int> >g[N];
int val[N],cnt[15];
int n,m,k,cnt1,cnt2,ans;
priority_queue<node,vector<node>,greater<node> >q1,q2;
int vis[N];
queue<pair<int,int> >q;
bool flag;
void slove(){
	vis[1]=1;
	for(auto i:g[1]){
		if(i.id<=n) q1.push({i,1});
		else q2.push({i,1});
	}
	node x,y;
	while(cnt2<n+cnt1){
	//	cerr<<q1.empty()<<" "<<q2.empty()<<endl;
		x=q1.top();
		if(!flag) y=q2.top();
	//	cerr<<x.to<<" "<<x.id<<endl;
	//	cerr<<y.to<<" "<<y.id<<endl;
		if(q1.empty()) break;
		while(vis[q1.top().to]){
			q1.pop();	
			if(q1.empty())
			break;
		}
		while((!q2.empty())&&vis[q2.top().to]) q2.pop();
		if(q1.empty()) break;
		if(q2.empty()) flag=1;
		x=q1.top();
		if(!flag) y=q2.top();
	//	cerr<<x.to<<" "<<x.id<<" "<<x.sum<<endl;
	//	cerr<<y.to<<" "<<y.id<<" "<<y.sum+val[y.to]<<endl;
		if(flag||x.sum<=y.sum+val[y.to]){
		//	cerr<<"not OK"<<endl;
			ans+=x.sum;
			vis[x.to]=1;
			q1.pop();
			if(x.id>n) cnt[x.id-n]++;
			for(auto v:g[x.to]){
				if(vis[v.id]) continue;
				if(v.id<=n)
					q1.push({v,x.to});
				else q2.push({v,x.to});
			}
		//	cerr<<"in "<<x.to<<endl;
		}
		if((!flag)&&x.sum>y.sum+val[y.to]){
	//		cerr<<"OK"<<endl;
			ans+=val[y.to]+y.sum;
		//	cerr<<ans<<endl;
			vis[y.to]=1;
			q2.pop();
			q.push({y.sum,y.to});
			for(auto v:g[y.to]){
				if(vis[v.id]) continue;
				q1.push({v,y.to});
			}
			cnt1++;
		//	cerr<<"build "<<y.to<<endl;
		}
		cnt2++;
	}
	pair<int,int> z;
	while(!q.empty()){
		z=q.front();
		q.pop();
		if(cnt[z.id-n]) continue;
		ans-=z.first+val[z.id];
	//	cerr<<"del "<<z.id<<endl;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++){
		cin>>val[i+n];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			g[i+n].push_back({w,j});
			g[j].push_back({w,i+n});
		}
	}
	slove();
	cout<<ans<<endl;
	return 0;
}

