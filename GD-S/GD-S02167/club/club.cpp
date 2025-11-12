#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct stu {
	int b[5],ma,j;
} a[N];
int t,n,dp[105][105][105];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			a[i].ma=-1,a[i].j=0;
			for(int j=1; j<=3; j++) {
				cin>>a[i].b[j];
				if(a[i].b[j]>a[i].ma)
					a[i].ma=a[i].b[j],a[i].j=j;
			}
		}
		if(n>200) {
			sort(a+1,a+1+n,[](const stu &A,const stu &B) {
				return A.ma>B.ma;
			});
			int cnt[5],full=0,ans=0;
			for(int i=1; i<=3; i++)cnt[i]=0;
			for(int i=1; i<=n; i++) {
				if(!full||(a[i].j!=full)) {
					ans+=a[i].ma;
					cnt[a[i].j]++;
					if(cnt[a[i].j]==n/2)full=a[i].j;
				} else {
					int ma=-1;
					for(int j=1; j<=3; j++) {
						if(j!=full)ma=max(ma,a[i].b[j]);
					}
					ans+=ma;
				}
			}
			cout<<ans<<'\n';
		} else {
			int ans=0;
			for(int i=0; i<=n/2; i++)
				for(int j=0; j<=n/2; j++)
					for(int k=0; k<=n/2; k++)
						dp[i][j][k]=-2e9;

			dp[0][0][0]=0;
			for(int i=1; i<=n; i++) {
				for(int j=0; j<=n/2; j++)
					for(int k=0; k<=n/2; k++) {
						int l=i-j-k;
						if(l>n/2)continue;
						if(l<0)break;
						if(j>0)
							dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i].b[1]);
						if(k>0)
							dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i].b[2]);
						if(l>0)
							dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i].b[3]);
						ans=max(ans,dp[j][k][l]);
					}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
