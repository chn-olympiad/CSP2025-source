#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5;
int t,n,d[3],W,v[maxn][3],ans=0,dp[3][maxn];
bool A=0;
pair<int,int> a1[maxn],a2[maxn],a3[maxn];
bool cmp(pair<int,int> a,pair<int,int> b) {
	return a.first>=b.first;
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>v[i][0]>>v[i][1]>>v[i][2];
		}
		for(int i=0; i<n; i++) {
			if(!v[i][1]&&!v[i][2]) {
				A=1;
			} else {
				A=0;
				break;
			}
		}
		for(int j=0; j<n; j++) {
			a1[j]=make_pair(v[j][0],j);
			a2[j]=make_pair(v[j][1],j);
			a3[j]=make_pair(v[j][2],j);
		}
		sort(a1,a1+n,cmp);
		sort(a2,a2+n,cmp);
		sort(a3,a3+n,cmp);
		W=n/2;
		if(A==1) {
			for(int i=0; i<W; i++) {
				ans+=a1[i].first;
			}
			cout<<ans<<endl;
			continue;
		} else {
			for(int i=0; i<W; i++) {
				ans+=a1[i].first+a2[i].first+a3[i].first;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}

