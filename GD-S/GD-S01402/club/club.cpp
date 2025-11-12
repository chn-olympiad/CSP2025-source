#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>> a[100010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > q[4];
signed main(){
	int T;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		int n;
		scanf("%lld",&n);
		for (int i=1;i<=n;i++){
			a[i].clear();
			for (int j=1;j<=3;j++){
				int x;
				scanf("%lld",&x);
				a[i].push_back({x,j});
			}
			sort(a[i].begin(),a[i].end(),greater<pair<int,int>>());
		}
		for (int i=1;i<=3;i++){
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > _;
			swap(_,q[i]);
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			int b=a[i][0].second;
			q[b].push({a[i][0].first-a[i][1].first,i});
			ans+=a[i][0].first;
			while(q[b].size()>n/2){
				int now=q[b].top().second;
				int dif=q[b].top().first;
				q[b].pop();
				int j=0;
				while(a[now][j].second!=b){
					j++;
				}
				if (j==0){
					b=a[now][1].second;
					q[b].push({a[now][1].first-a[now][2].first,now});
					ans-=dif;
				}
				else if(j==1){
					b=a[now][2].second;
					q[b].push({0x3f3f3f3f,now});
					ans-=dif;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
	
}
