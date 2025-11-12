#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<pair<int ,int >  > a[N];
int n;

void sol(){
	priority_queue<pair<int ,int > >q[4];
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int qq,ww,ee;
		cin>>qq>>ww>>ee;
		a[i].push_back({qq,1});
		a[i].push_back({ww,2});
		a[i].push_back({ee,3});
		sort(a[i].begin(),a[i].end());
		reverse(a[i].begin(),a[i].end());
		int id=a[i][0].second;
		if(q[id].size()<n/2)q[id].push({a[i][1].first-a[i][0].first,i}),ans+=a[i][0].first;
		else {
			int vid=q[id].top().second;
			int vs=-q[id].top().first;
			if(vs<a[i][0].first-a[i][1].first){
				q[id].pop(); 
				q[id].push({a[i][1].first-a[i][0].first,i});
				int nx=a[vid][1].second;
				ans-=a[vid][0].first;
				ans+=a[vid][1].first;
				ans+=a[i][0].first;
				q[nx].push({a[vid][2].first-a[vid][1].first,vid});
			}else {
				int nx=a[i][1].second;
				ans+=a[i][1].first;
				q[nx].push({a[i][2].first-a[i][1].first,i});
			}
			
		}
	}
	//cout<<q[1].size()<<' '<<q[2].size()<<'\n';
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)a[i].clear();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)sol();
	return 0;
}

