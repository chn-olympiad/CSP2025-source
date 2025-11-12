#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
int t,n,a[N][3],ans;
priority_queue<int> q[3];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		for(int i=0;i<=2;i++) q[i]=priority_queue<int>();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			int ps=0,num=-1145141919;
			for(int j=0;j<=2;j++) {
				cin>>a[i][j];
				if(a[i][j]>a[i][ps]) ps=j;
			}
			ans+=a[i][ps];
			for(int j=0;j<=2;j++) {
				if(j==ps) continue;
				num=max(num,a[i][j]-a[i][ps]);
			}
			q[ps].push(num);
		}
		for(int i=0;i<=2;i++) {
			while(q[i].size()>n/2) {
				int x=q[i].top(); q[i].pop();
				ans+=x;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
