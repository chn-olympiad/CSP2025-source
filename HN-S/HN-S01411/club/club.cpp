#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

int limi[4];
bool chk[MAXN];

int t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int o=0;o<t;o++){
		limi[1]=limi[2]=limi[3]=0;
		int n;
		int ans=0;
		priority_queue <pair<int,pair<int,int> > > pq;
		cin>>n;
		for(int i=1;i<=n;i++) chk[i]=false;
		
		for(int i=1;i<=n;i++){
			int t1,t2,t3;
			cin>>t1>>t2>>t3;
			pq.push(make_pair(t1,make_pair(i,1)));
			pq.push(make_pair(t2,make_pair(i,2)));
			pq.push(make_pair(t3,make_pair(i,2)));
		}
		
		while(!pq.empty()){
			int t1=pq.top().first;
			int t2=pq.top().second.first;
			int t3=pq.top().second.second;
			pq.pop();
			if(chk[t2]||limi[t3]>(n/2)) continue;
			chk[t2]=true;
			ans+=t1;	
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
