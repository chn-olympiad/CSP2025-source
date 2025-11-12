//GZ-S00188 贵阳市第三中学 徐东灿
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int t,n;
struct node{
	int a,b,c;
}x[N];
int v[4][2];
long long dp[N][3];
void solve() {
	memset(v,0,sizeof v);
	memset(dp,0,sizeof dp);
	cin>>n;
	for (int i=1;i<=n;++i) {
		cin>>x[i].a>>x[i].b>>x[i].c;
	}
	sort(x+1,x+1+n,[](const node& u,const node& v) {
		if (u.a!=v.a) return u.a>v.a;
		else if (u.b!=v.b) return u.b>v.b;
		else return u.c>v.c;
	});
	
	
	for (int i=1;i<=n;i++) {
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		dp[i][2]=dp[i-1][2];
		if (v[0][1]<n/2) {
			dp[i][0]+=x[i].a;
			v[0][1]++;
		}
		else {
			if (v[0][0]<n/2) {
				dp[i][0]=max(dp[i-1][1],dp[i-1][2])+x[i].a;
				v[0][0]++;
			}
		}
		if (v[1][1]+1<=n/2) {
			dp[i][1]+=x[i].b;
			v[1][1]++;
		}
		else {
			if (v[1][0]<n/2) {
				dp[i][1]=max(dp[i-1][0],dp[i-1][2])+x[i].b;
				v[1][0]++;
			}
		}
		if (v[2][1]<n/2) {
			dp[i][2]+=x[i].c;
			v[2][1]++;
		}
		else {
			if (v[2][0]<n/2) {
				dp[i][2]=max(dp[i-1][0],dp[i-1][1])+x[i].c;
				v[2][0]++;
			}
		}
	}
	cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while (t--) {
		solve();
	}
	
	return 0;
} 
