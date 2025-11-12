#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],h[N][4],p[N];
void clear(){
	for(int i=1;i<=n;i++){
		p[i]=0;
	}
}
int main(){
	fstream cin("club.in",ios::in);
	fstream cout("club.out",ios::out);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			h[i][0]=0,h[i][1]=1,h[i][2]=2;
			sort(h[i],h[i]+3,[&](int x,int y)->bool{
				return a[i][x]>a[i][y];
			});
		}
//		for(int i=1;i<=n;i++){
//			cerr<<h[i][0]<<' '<<h[i][1]<<' '<<h[i][2]<<'\n';
//		}
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q[3];
		for(int i=1;i<=n;i++){
			q[h[i][0]].push({a[i][h[i][0]]-a[i][h[i][1]],i});
		}
		for(int i=0;i<=2;i++){
			while(q[i].size()>n/2){
				pair<int,int>tp=q[i].top();q[i].pop();
				q[h[tp.second][++p[tp.second]]].push({a[tp.second][h[tp.second][p[tp.second]]]-a[tp.second][h[tp.second][p[tp.second]+1]],tp.second});
			}
		}
		long long ans=0;
		for(int i=0;i<3;i++){
			while(!q[i].empty()){
				int t=q[i].top().second;q[i].pop();
				ans+=a[t][i];
//				cerr<<i<<' '<<t<<' '<<a[t][i]<<'\n';
			}
		}
		cout<<ans<<'\n';
		clear();
	}
	return 0;
}
