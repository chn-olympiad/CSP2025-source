#include<bits/stdc++.h>
#define N 10020
#define pr pair<int,int>
#define fir first
#define sec second
#define mkp(A,B) make_pair(A,B)
using namespace std;
priority_queue<pr,vector<pr>,greater<pr> > q;
int n,m,k,nk;
bool vis[N];
vector<pr > mp[N];
int c[20];
long long ans;
int main(){
	freopen("road3.in","r",stdin);
	//freopen("road1.out","w",stdout);
	//freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	nk=n+k;
	for(int i=1,x,y,w;i<=m;i++){
		cin>>x>>y>>w;
		mp[x].push_back(make_pair(y,w));
		mp[y].push_back(make_pair(x,w));
	}
	for(int j=n+1;j<=nk;j++){
		cin>>c[j];
		for(int i=1,w;i<=n;i++){
			cin>>w;
			mp[j].push_back(make_pair(i,w));
			mp[i].push_back(make_pair(j,w));
		}
	}
	q.push(mkp(0,1));
	int cc=0;
	while(!q.empty()){
		if(cc>nk) break;
		int d=q.top().fir,p=q.top().sec;
		q.pop();
		if(vis[p]) continue;
		cc++;
		vis[p]=1;
		ans+=d;
		for(int i=0,sz=mp[p].size();i<sz;i++){
			if(!vis[mp[p][i].fir]){
				q.push(mkp(mp[p][i].sec,mp[p][i].fir));
			}
		}
	}
	cout<<ans;
	return 0;
}

