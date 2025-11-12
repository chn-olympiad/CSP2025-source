#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
struct node{
	int x,y,plse;
}road[M];
struct edge{
	int opp,plse[N];
}countryside[K];
int ans=0;
vector<pii>rd[N+10];
int vis[N+10]={0},ans_vis=0;
void make_min_tree(int x){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	set<int>st;
	q.push(make_pair(0,x));
	while(ans_vis!=n){
		//cout<<1<<endl;
		auto d=q.top();
		st.insert(d.second);
		vis[d.second]=1;
		if(d.second<=n) ans_vis++;
		q.pop();
		for(auto nd:rd[d.second]){
			if(nd.second!=d.second&&!vis[nd.second]){
				ans+=nd.first;
				q.push(make_pair(nd.first,nd.second));
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].x>>road[i].y>>road[i].plse;
		rd[road[i].x].push_back(make_pair(road[i].plse,road[i].y));
		rd[road[i].y].push_back(make_pair(road[i].plse,road[i].x));
	}
	for(int i=1;i<=k;i++){
		cin>>countryside[i].opp;
		for(int j=1;j<=n;j++){
			cin>>countryside[i].plse[j];
			rd[j].push_back(make_pair(countryside[i].plse[j],n+i));
			rd[n+i].push_back(make_pair(countryside[i].plse[j],j));
		}
	}
	make_min_tree(1);
	cout<<ans;
	return 0;
}