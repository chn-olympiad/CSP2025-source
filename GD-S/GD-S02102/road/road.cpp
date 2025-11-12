#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct node{
	int u,w;
	operator < (int &_u,int &_w) const{
		_u=u;
		_w=w;
		u<w;
	}
};
vector<node> ve[N];
priority_queue<node> q;
int dis[N],n,m,k;
bool vis[N];
void dj(){
	dis[1]=0;
	vis[1]=1;
	q.push_back({1,0});
	while(!q.empty()){
		
	}
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	for(int i=1;i<=n;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		ve[uu].push_back({vv,ww});
		ve[vv].push_back({uu,ww});
	}
	dj();
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
