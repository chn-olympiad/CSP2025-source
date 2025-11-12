#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=1e5+5;
int n;
ll a[N][4];
int to[N][4];
int cnt[4];
vector<pair<ll,int>>v[4];
void init() {
	memset(to,0,sizeof(to));
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=3; i++) {
		v[i].clear();
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		init();
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			pair<ll,int>p[4];
			for(int j=1; j<=3; j++) {
				p[j]= {a[i][j],j};
			}
			sort(p+1,p+4,greater<pair<ll,int>>());
			for(int j=1; j<=3; j++) {
				to[i][j]=p[j].second;
			}
		}
		ll ans=0;
		for(int i=1; i<=n; i++) {
			ans+=a[i][to[i][1]];
			cnt[to[i][1]]++;
			v[to[i][1]].push_back({a[i][to[i][1]]-a[i][to[i][2]],i});
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2) {
			cout<<ans<<endl;
			continue;
		}
//		cout<<"NOWANS:"<<ans<<endl;
		for(int i=1; i<=3; i++) {
			if(cnt[i]>n/2) {
				sort(v[i].begin(),v[i].end(),greater<pair<ll,int>>());
				int num=cnt[i]-n/2;
				for(int j=v[i].size()-1; j>=v[i].size()-num; j--) {
//					cout<<endl<<"now::"<<v[i][j].first<<" "<<v[i][j].second<<endl;
					int pos=v[i][j].second;
//					v[to[pos][2]].push_back({a[pos][to[pos][2]]-a[pos][to[pos][3]],pos});
					ans-=v[i][j].first;
//					cnt[to[pos][2]]++;
//					cnt[to[pos][1]]--;
				}
				break;
			}
		}
//		for(int i=1; i<=3; i++) {
//			if(cnt[i]>n/2) {
//				sort(v[i].begin(),v[i].end(),greater<pair<ll,int>>());
//				int num=cnt[i]-n/2;
//				for(int j=v[i].size()-1; j>=v[i].size()-num; j--) {
//					int pos=v[i][j].second;
//					ans-=v[i][j].first;
//					cnt[to[pos][3]]++;
//					cnt[to[pos][2]]--;
//				}
//				break;
//			}
//		}
		cout<<ans<<endl;
	}
	return 0;
}
