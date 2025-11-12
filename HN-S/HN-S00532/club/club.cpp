#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N = 2e5 + 10;
int a[N][4],n;
priority_queue<pii,vector<pii>,greater<pii>>q[4];
int aa[N],www;
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		while(q[1].size()) q[1].pop();
		while(q[2].size()) q[2].pop();
		while(q[3].size()) q[3].pop();
		www=0;
		int ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1; i<=n; i++) {
			int id=-1,maxn=-1;
			for(int j=1; j<=3; j++) {
				if(a[i][j]>maxn) maxn=a[i][j],id=j;
			}
			q[id].emplace(make_pair(maxn,i));
			ans+=maxn;
		}
		int id=-1;
		for(int i=1; i<=3; i++) if(q[i].size()>n/2) id=i;
		if(id==-1) {
			cout<<ans<<'\n';
		} else {
			int nn=q[id].size()-n/2;
			aa[++www]=ans;
			while(q[id].size()) {
				int i=q[id].top().second;
				int maxn=-1;
				for(int j=1; j<=3; j++) {
					if(j==id) continue;
					if(a[i][j]>maxn) maxn=a[i][j];
				}
				aa[++www]=maxn-q[id].top().first;
				q[id].pop();
			}
			int aans=0;
			sort(aa+1,aa+www+1,[](int x,int y){
				return x>y;
			});
			for(int i=1;i<=nn+1;i++) aans+=aa[i];
			cout<<aans<<'\n';
		}
	}
	return 0;
}
/*
3
4
4 2 1 3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
