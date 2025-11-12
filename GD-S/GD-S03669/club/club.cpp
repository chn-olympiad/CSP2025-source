#include <bits/stdc++.h>
#define int long long
constexpr int maxn=200010;
using namespace std;
int n, t;
int a[8][maxn], c[8], ans=0, vis[maxn]; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	while (t--){
		memset(vis, 0, sizeof vis);
		ans=0;
		c[1]=c[2]=c[3]=0; 
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq[4];
		cin>>n;
		for (int i=1; i<=n; i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if (a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){
				c[1]++;
				ans+=a[1][i];
				pq[1].push({abs(a[1][i]-a[2][i]), {2, i}});
				pq[1].push({abs(a[1][i]-a[3][i]), {3, i}});
			}
			if (a[2][i]>a[1][i]&&a[2][i]>=a[3][i]){
				c[2]++;
				ans+=a[2][i];
				pq[2].push({abs(a[1][i]-a[2][i]), {1, i}});
				pq[2].push({abs(a[3][i]-a[2][i]), {3, i}});
			}
			if (a[3][i]>a[2][i]&&a[3][i]>a[1][i]){
				c[3]++;
				ans+=a[3][i];
				pq[3].push({abs(a[3][i]-a[2][i]), {1, i}});
				pq[3].push({abs(a[1][i]-a[3][i]), {2, i}});
			}
		}
		for (int i=1; i<=3; i++){
			while (c[i]*2>n){
				int u=pq[i].top().second.first, v=pq[i].top().first, w=pq[i].top().second.second;
				pq[i].pop();
				if (vis[w]) continue;
				vis[w]=1;
				if (c[u]*2==n){
					continue;
				}
//				cout<<u<<" "<<v<<" "<<w<<"\n";
				c[i]--;
				c[u]++;
				ans-=v;
			}
		}
//		cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
} 
