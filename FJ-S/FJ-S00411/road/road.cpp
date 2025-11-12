#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct Edge{
	int u,v;
	LL w;
};

int n,m,k,inp1,inp2;
LL inp3,ans;

inline bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

//bool check0(vector<vector<Edge> >& Gorg){
//	vector<bool> vis(n+1,false);
//	queue<int> q;
//	int cnt = 0;
//	q.push(1);
//	while(!q.empty()){
//		int cur = q.front();
//		q.pop();
//		vis[cur] = true;
//		for(auto nex : Gorg[cur]){
//			if(!vis[nex.u]){
//				q.push(nex.u);
//				cnt++;
//			}
//		}
//	}
//	return cnt==n;
//}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k;
	vector<vector<Edge> > Gorg(n+1,vector<Edge>(0)), Gnew(k+1,vector<Edge>(n+1,{0,0,0ll}));
	for(int i=1;i<=m;i++){
		cin>>inp1>>inp2>>inp3;
		Gorg[inp1].push_back({inp1,inp2,inp3});
		Gorg[inp2].push_back({inp2,inp1,inp3});
		ans += inp3;
//		edges[i].u = inp1;
//		edges[i].v = inp2;
//		edges[i].w = inp3;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>Gnew[i][j].w;
			Gnew[i][j].u = i;
			Gnew[i][j].v = j;
		}
	}
	
	if(k==0){
		cout<<ans<<'\n';
//		bool canGo = false;
//		sort(edges+1,edges+m+1,cmp);
//		vector<vector<Edge> > Gcur(n+1,vector<Edge>(0));
//		for(int i=1;i<=m;i++){
//			Gcur[edges[i].u].push_back(edges[i]);
//			Gcur[edges[i].v].push_back({edges[i].v,edges[i].u,edges[i].w});
//			ans += edges[i].w;
//			if(check0(Gcur)){
//				cout<<ans<<'\n';
//				canGo = true;
//				break;
//			}
//		}
//		if(!canGo)cout<<0<<'\n';
	}
	else{
		cout<<n+m+ans<<'\n';
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4


*/
