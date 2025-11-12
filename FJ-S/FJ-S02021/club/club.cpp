#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
int T,n,lim;
typedef pair<pair<int,int>,pair<int,int> > pii;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;lim=n/2;
		if(n==2){
			int x,y,z,u,v,w;
			cin>>x>>y>>z>>u>>v>>w;
			cout<<max({x+v,x+w,y+u,y+w,z+u,z+v})<<endl;
			continue;
		}
		vector<pair<int,int> >a[N];
		queue<pair<int,int> >que;
		for(int i=1;i<=n;i++){
			que.push(make_pair(i,2ll));
			for(int j=1,aij;j<=3;j++){
				cin>>aij;
				a[i].push_back(make_pair(aij,j));
				sort(a[i].begin(),a[i].end());
			}
		}
		priority_queue<pii,vector<pii>,greater<pii> >q[5];
		while(!que.empty()){
			int i=que.front().first,j=que.front().second;
			int cb=a[i][j].second;
			if(q[cb].size()==lim){
				pair<int,int>x=q[cb].top().second;
				if(a[i][j].first+a[x.first][x.second-1].first>a[i][j-1].first+a[x.first][x.second].first){
					q[cb].pop();
					x.second--;
					que.push(x);
					q[cb].push(make_pair(a[i][j],que.front()));
					que.pop();
				}else{
					que.push(make_pair(i,j-1));
					que.pop();
				}
			}else{
				q[cb].push(make_pair(a[i][j],que.front()));
				que.pop();
			}
		}
		int ans=0;
		for(int i=1;i<=3;i++){
			while(!q[i].empty()){
				ans+=q[i].top().first.first;
				q[i].pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
