#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
priority_queue<pair<int,int>> q[4];
pair<int,int> a[100005][4];
int pos[100005];
int ans;
int cnt[4];

signed main(){
	cin.tie(0),cout.tie(0);
	cin.sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		for(int i=1;i<=3;i++){
			while(!q[i].empty())q[i].pop();
		}
		memset(cnt,0,sizeof(cnt));
		ans=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			vector<pair<int,int>> v;
			for(int j=1;j<=3;j++){
				int x;
				cin >> x;
				a[i][j]={x,j};
			}
			sort(a[i]+1,a[i]+1+3);
			pos[i]=3;
			ans+=a[i][3].first;
			cnt[a[i][3].second]++;
			q[a[i][3].second].push({a[i][2].first-a[i][3].first,i});
			if(cnt[a[i][3].second]>n/2){
				cnt[a[i][3].second]--;
				int p=a[i][3].second;
				while(!q[p].empty()){
					auto x=q[p].top();
					q[p].pop();
					if(pos[x.second]==1)continue;
					else {
						ans+=x.first;
						if(pos[x.second]==3)q[a[x.second][pos[x.second]-1].second].push({a[x.second][pos[x.second]-1].first-a[x.second][pos[x.second]-2].first,x.second});
						pos[x.second]--;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
