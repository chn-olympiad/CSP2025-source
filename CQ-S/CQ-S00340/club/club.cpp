#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],ans;
void dfs(int x,int sum,int s1,int s2,int s3) {
	if (x==n+1) {
		ans=max(ans,sum);
		return ; 
	}
	for (int j=1;j<=3;j++) {
		if ((s1+(j==1)<=n/2) && (s2+(j==2)<=n/2) && (s3+(j==3)<=n/2)) {
			dfs(x+1,sum+a[x][j],s1+(j==1),s2+(j==2),s3+(j==3));
		}
	}
}
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=3;j++) {
				cin>>a[i][j];
			}
		}
		if (n<=30){
			dfs(1,0,0,0,0);
		}else if (a[1][2]==0 && a[1][3]==0) {
			priority_queue<int> q;
			for (int i=1;i<=n;i++) q.push(-a[i][1]);
			int s1=0;
			while (!q.empty()) {
				if (s1<n/2) {
					s1++;
					ans-=q.top();
				}
				q.pop();
			}
		}else {
			priority_queue<pair<int,int> > q;
			for (int i=1;i<=n;i++) q.push({-a[i][1],1}),q.push({-a[i][2],2});
			int s1=0,s2=0;
			while (!q.empty()) {
				if (q.top().second==1 && s1<n/2) {
					s1++;
					ans-=q.top().first;
				}else {
					s2++;
					ans-=q.top().first;
				}
				q.pop();
			}
		}
		cout<<ans<<endl;
		ans=0;
	} 
	return 0;
}
