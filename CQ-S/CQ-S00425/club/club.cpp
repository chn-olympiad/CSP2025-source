#include <bits/stdc++.h>
using namespace std;
#define I cin>>
#define O cout<<
#define PII pair<int,int>
#define tp tuple<int,int,int>
#define fi(x) (x.first)
#define se(x) (x.second)
int t,n,x,vis[100005],sum[5];
long long ans;
vector<pair<int,int> > a[100005];
bool cmp(vector<pair<int,int> > cp1,vector<pair<int,int> > cp2){
	return cp1[0].first>cp2[0].first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	I t;
	while(t--){
		I n;
		for(int i=1;i<=n;i++){
			a[i].clear();
			for(int j=1;j<=3;j++) I x,a[i].push_back(make_pair(x,j));
			sort(a[i].begin(),a[i].end(),greater<pair<int,int> >());
		}
		memset(vis,0,sizeof(vis));
		sum[1]=0,sum[2]=0,sum[3]=0,ans=0;
		sort(a+1,a+n+1,cmp);
		priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q[4];
		for(int i=1;i<=n;i++){
			if(sum[a[i][0].second]<n/2){
				sum[a[i][0].second]++,ans+=a[i][0].first;
				q[a[i][0].second].push(make_pair(a[i][0].first-a[i][1].first,make_pair(i,1)));
			}else{
				if(a[i][0].first-q[a[i][0].second].top().first>a[i][1].first){
					ans-=q[a[i][0].second].top().first;
					ans+=a[i][0].first;
					int yuani=q[a[i][0].second].top().second.first,yuans=q[a[i][0].second].top().second.second;
					sum[a[yuani][yuans].second]++;
					q[a[i][0].second].pop();
					if(yuans==1) q[a[yuani][1].second].push(make_pair(a[i][1].first-a[i][2].first,make_pair(i,2)));
					q[a[i][0].second].push(make_pair(a[i][0].first-a[i][1].first,make_pair(i,1)));
				}else{
					sum[a[i][1].second]++,ans+=a[i][1].first;
					q[a[i][1].second].push(make_pair(a[i][1].first-a[i][2].first,make_pair(i,2)));
				} 
			}
		} 
		O ans << "\n";
	}
	return 0;
}
