#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N][5],ans,t;
priority_queue<int,vector<int>,greater<int>>
pq1,pq2,pq3;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t--;){
		while(pq1.size())pq1.pop();while(pq2.size())pq2.pop();while(pq3.size())pq3.pop();
		cin>>n;ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				ans+=a[i][1];
				pq1.push(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				ans+=a[i][2];
				pq2.push(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
				ans+=a[i][3];
				pq3.push(min(a[i][3]-a[i][2],a[i][3]-a[i][1]));
			}
		}
		//cerr<<pq1.size()<<' '<<pq2.size()<<' '<<pq3.size()<<'\n';
		while(pq1.size()>(n>>1))ans-=pq1.top(),pq1.pop();
		while(pq2.size()>(n>>1))ans-=pq2.top(),pq2.pop();
		while(pq3.size()>(n>>1))ans-=pq3.top(),pq3.pop();
		//cerr<<pq1.size()<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
} 

/*
14:52
*/
