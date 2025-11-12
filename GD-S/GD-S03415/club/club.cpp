#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int cnt[4];
long long a[N][4];
bool vis[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--) {
		int n;cin>>n;
		priority_queue<array<long long,3> > Q;
		for(int i=1;i<=n;i++) {
			vis[i]=0;
			for(int j=0;j<3;j++) cin>>a[i][j],Q.push({a[i][j],i,j}); 
		}
		priority_queue<long long> q[3][3];
		long long ans=0;cnt[0]=cnt[1]=cnt[2]=0;
		while(cnt[0]+cnt[1]+cnt[2]<n&&!Q.empty()) {
			auto cur=Q.top();Q.pop();
			long long x=cur[0];int i=cur[1],j=cur[2];
			if(vis[i]) continue;
			if(cnt[j]+1<=n/2) {
				ans+=x,vis[i]=1,cnt[j]++;
				for(int l=0;l<3;l++) {
					if(l==j) continue;
					q[j][l].push(a[i][l]-x);
				}
			}
			else {
				for(int l=0;l<3;l++) {
					if(l==j) continue;
					if(!q[j][l].empty()) Q.push({x+q[j][l].top(),i,l}),q[j][l].pop();
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
