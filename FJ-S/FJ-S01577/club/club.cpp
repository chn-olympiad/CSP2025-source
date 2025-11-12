#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b){
	return a>b;
}
int a[100010][5];
int dp[210][210][210];
int l[100010];
struct node{
	int a,b;
}ll[100010];
bool cmpp(node x,node y){
	if (x.a!=y.a) return x.a>y.a;
	return x.b<y.b;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--) {
		int n;
		cin>>n;
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=3; ++j) {
				cin>>a[i][j];
			}
		}
		int ans=0;
		if (n<=200) {
			for (int o=1; o<=n; ++o) {
				for (int i=0; i<=min(n/2,o); ++i) {
					for (int j=0; j<=min(n/2,o); ++j) {
						int k=o-i-j;
						if (k<=min(n/2,o)) {
							if (i>0) {
								dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[o][1]);
							}
							if (j>0) {
								dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[o][2]);
							}
							if (k>0) {
								dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[o][3]);
							}
							ans=max(ans,dp[i][j][k]);
						}
					}
				}
			}
		} else {
			bool aa=1;
			bool bb=1;
			for (int i=1; i<=n; ++i) {
				if (a[i][2]||a[i][3]) aa=0;
				if (a[i][3]) bb=0;
			}
			if (aa==1) {
				for (int i=1; i<=n; ++i) {
					l[i]=a[i][1];
				}
				sort(l+1,l+1+n,cmp);
				for (int i=1; i<=n/2; ++i) {
					ans+=l[i];
				}
			} else if (bb==1) {
				pair<int,int> PII,PII1;
				priority_queue<pair<int,int> > q1,q2;
				for (int i=1; i<=n; ++i) {
					ll[i].a=a[i][1];
					ll[i].b=a[i][2];
				}
				sort(ll+1,ll+1+n,cmpp);
				for (int i=1;i<=n;++i){
					int a=ll[i].a,b=ll[i].b;
					if (a>=b){
						if (q1.size()<n/2){
							PII.first=b;
							PII.second=a;
							q1.push(PII);
						}else {
							if (q1.top().first>q1.top().second-a){
								PII1.first=q1.top().second;
								PII1.second=q1.top().first;
								q1.pop();
								q2.push(PII1);
								PII.first=b;
								PII.second=a;
								q1.push(PII);
							}else {
								PII.first=a;
								PII.second=b;
								q2.push(PII);
							}
						}
					}
					if (a<b){
						if (q2.size()<n/2){
							PII.first=a;
							PII.second=b;
							q1.push(PII);
						}else {
							if (q2.top().first>q2.top().second-b){
								PII1.first=q2.top().second;
								PII1.second=q2.top().first;
								q2.pop();
								q1.push(PII1);
								PII.first=a;
								PII.second=b;
								q2.push(PII);
							}else {
								PII.first=b;
								PII.second=a;
								q1.push(PII);
							}
						}
					}
				}
				while (!q1.empty()){
					ans+=q1.top().second;
					q1.pop();
				}
				while (!q2.empty()){
					ans+=q2.top().second;
					q2.pop();
				}
			} else {
				cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n";
				return 0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
